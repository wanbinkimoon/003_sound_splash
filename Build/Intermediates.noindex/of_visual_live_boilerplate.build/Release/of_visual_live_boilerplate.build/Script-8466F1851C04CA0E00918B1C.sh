#!/bin/sh
echo "$GCC_PREPROCESSOR_DEFINITIONS";
APPSTORE=`expr "$GCC_PREPROCESSOR_DEFINITIONS" : ".*APPSTORE=\([0-9]*\)"`
if [ -z "$APPSTORE" ] ; then
echo "Note: Not copying bin/data to App Package or doing App Code signing. Use AppStore target for AppStore distribution";
else
# Copy bin/data into App/Resources
rsync -avz --exclude='.DS_Store' "${SRCROOT}/bin/data/" "${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/data/"

# Strip 32bit from fmod dylib
lipo -remove i386 "${TARGET_BUILD_DIR}/${PRODUCT_NAME}.app/Contents/Frameworks/libfmodex.dylib" -o "${TARGET_BUILD_DIR}/${PRODUCT_NAME}.app/Contents/Frameworks/libfmodex.dylib" 

# ---- Code Sign App Package ----

# WARNING: You may have to run Clean in Xcode after changing CODE_SIGN_IDENTITY!

# Verify that $CODE_SIGN_IDENTITY is set
if [ -z "${CODE_SIGN_IDENTITY}" ] ; then
echo "CODE_SIGN_IDENTITY needs to be set for framework code-signing"
exit 0
fi

if [ -z "${CODE_SIGN_ENTITLEMENTS}" ] ; then
echo "CODE_SIGN_ENTITLEMENTS needs to be set for framework code-signing!"

if [ "${CONFIGURATION}" = "Release" ] ; then
exit 1
else
# Code-signing is optional for non-release builds.
exit 0
fi
fi

ITEMS=""

FRAMEWORKS_DIR="${TARGET_BUILD_DIR}/${FRAMEWORKS_FOLDER_PATH}"
echo "$FRAMEWORKS_DIR"
if [ -d "$FRAMEWORKS_DIR" ] ; then
FRAMEWORKS=$(find "${FRAMEWORKS_DIR}" -depth -type d -name "*.framework" -or -name "*.dylib" -or -name "*.bundle" | sed -e "s/\(.*framework\)/\1\/Versions\/A\//")
RESULT=$?
if [[ $RESULT != 0 ]] ; then
exit 1
fi

ITEMS="${FRAMEWORKS}"
fi

LOGINITEMS_DIR="${TARGET_BUILD_DIR}/${CONTENTS_FOLDER_PATH}/Library/LoginItems/"
if [ -d "$LOGINITEMS_DIR" ] ; then
LOGINITEMS=$(find "${LOGINITEMS_DIR}" -depth -type d -name "*.app")
RESULT=$?
if [[ $RESULT != 0 ]] ; then
exit 1
fi

ITEMS="${ITEMS}"$'\n'"${LOGINITEMS}"
fi

# Prefer the expanded name, if available.
CODE_SIGN_IDENTITY_FOR_ITEMS="${EXPANDED_CODE_SIGN_IDENTITY_NAME}"
if [ "${CODE_SIGN_IDENTITY_FOR_ITEMS}" = "" ] ; then
# Fall back to old behavior.
CODE_SIGN_IDENTITY_FOR_ITEMS="${CODE_SIGN_IDENTITY}"
fi

echo "Identity:"
echo "${CODE_SIGN_IDENTITY_FOR_ITEMS}"

echo "Entitlements:"
echo "${CODE_SIGN_ENTITLEMENTS}"

echo "Found:"
echo "${ITEMS}"

# Change the Internal Field Separator (IFS) so that spaces in paths will not cause problems below.
SAVED_IFS=$IFS
IFS=$(echo -en "\n\b")

# Loop through all items.
for ITEM in $ITEMS;
do
echo "Stripping invalid archs '${ITEM}'"
lipo -remove i386 "${ITEM}" -o "${ITEM}"
echo "Signing '${ITEM}'"
codesign --force --verbose --sign "${CODE_SIGN_IDENTITY_FOR_ITEMS}" --entitlements "${CODE_SIGN_ENTITLEMENTS}" "${ITEM}"
RESULT=$?
if [[ $RESULT != 0 ]] ; then
echo "Failed to sign '${ITEM}'."
IFS=$SAVED_IFS
exit 1
fi
done

# Restore $IFS.
IFS=$SAVED_IFS

fi

