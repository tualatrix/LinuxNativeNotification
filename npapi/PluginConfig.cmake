#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for Linux Native Notification
#
#\**********************************************************/

set(PLUGIN_NAME "LinuxNativeNotification")
set(PLUGIN_PREFIX "LNN")
set(COMPANY_NAME "imtx")

# ActiveX constants:
set(FBTYPELIB_NAME LinuxNativeNotificationLib)
set(FBTYPELIB_DESC "LinuxNativeNotification 1.0 Type Library")
set(IFBControl_DESC "LinuxNativeNotification Control Interface")
set(FBControl_DESC "LinuxNativeNotification Control Class")
set(IFBComJavascriptObject_DESC "LinuxNativeNotification IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "LinuxNativeNotification ComJavascriptObject Class")
set(IFBComEventSource_DESC "LinuxNativeNotification IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 3f1c7949-15b2-5e89-9ad4-c695ce2b76da)
set(IFBControl_GUID c0e503bf-4119-511c-9c75-5f070e95890d)
set(FBControl_GUID d14af202-2c02-5171-8afd-2b6bb8a4b708)
set(IFBComJavascriptObject_GUID f6d92e48-dfe9-5ade-841b-98252c7e7642)
set(FBComJavascriptObject_GUID f7463c2c-3b49-591c-bef2-2ee2b7ef1e9e)
set(IFBComEventSource_GUID 71c25c9c-3120-5009-bc13-a3de1354ec73)

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "imtx.LinuxNativeNotification")
set(MOZILLA_PLUGINID "imtx.me/LinuxNativeNotification")

# strings
set(FBSTRING_CompanyName "IMTX")
set(FBSTRING_FileDescription "Implementation to have Google Chrome's Webkit Notifications pipe through notify-osd.")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2012 IMTX")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "Linux Native Notification")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "Linux Native Notification")
set(FBSTRING_MIMEType "application/x-linuxnativenotification")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

#set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 1)
set(FBMAC_USE_COCOA 1)
set(FBMAC_USE_COREGRAPHICS 1)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
