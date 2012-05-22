/**********************************************************\

  Auto-generated LinuxNativeNotificationAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "LinuxNativeNotification.h"

#include <libnotify/notify.h>

#ifndef H_LinuxNativeNotificationAPI
#define H_LinuxNativeNotificationAPI

class LinuxNativeNotificationAPI : public FB::JSAPIAuto
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @fn LinuxNativeNotificationAPI::LinuxNativeNotificationAPI(const LinuxNativeNotificationPtr& plugin, const FB::BrowserHostPtr host)
    ///
    /// @brief  Constructor for your JSAPI object.
    ///         You should register your methods, properties, and events
    ///         that should be accessible to Javascript from here.
    ///
    /// @see FB::JSAPIAuto::registerMethod
    /// @see FB::JSAPIAuto::registerProperty
    /// @see FB::JSAPIAuto::registerEvent
    ////////////////////////////////////////////////////////////////////////////
    LinuxNativeNotificationAPI(const LinuxNativeNotificationPtr& plugin, const FB::BrowserHostPtr& host) :
        m_plugin(plugin), m_host(host)
    {
        notify_init("linuxnativenotification");

        registerMethod("notify",      make_method(this, &LinuxNativeNotificationAPI::notify));
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @fn LinuxNativeNotificationAPI::~LinuxNativeNotificationAPI()
    ///
    /// @brief  Destructor.  Remember that this object will not be released until
    ///         the browser is done with it; this will almost definitely be after
    ///         the plugin is released.
    ///////////////////////////////////////////////////////////////////////////////
    ~LinuxNativeNotificationAPI()
    {
        notify_uninit();
    };

    LinuxNativeNotificationPtr getPlugin();

    // Method notify
    FB::variant notify(const FB::variant& summary,
                       const FB::variant& body,
                       const FB::variant& icon);

private:
    LinuxNativeNotificationWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;
    std::string m_previous_summary;
};

#endif // H_LinuxNativeNotificationAPI

