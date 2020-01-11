# Sound Splash
----–––––––––––
## How to fix build errors 
 
In case build fails after of generator adds the needed extensions add this script in 
`[TARGET NAME] > Build Phases > Link Binary ~ Run script` at the end of the area.    
```
rm -R -f "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/data"; mkdir -p "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/"; cp -f -R bin/data "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/";
```
