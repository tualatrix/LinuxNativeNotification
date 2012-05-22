/**********************************************************\

  Auto-generated LinuxNativeNotificationAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include "LinuxNativeNotificationAPI.h"

// Standard includes
#include <string>
#include <fstream>
// libcurl header
#include <curl/curl.h>

size_t simple_callback(void *ptr, size_t size, size_t nmemb, void *stream)
{
    std::ofstream & of = *(std::ofstream *)stream;

    of.write((char *)ptr, size*nmemb);

    return size * nmemb;
}

// Method notify
FB::variant LinuxNativeNotificationAPI::notify(const FB::variant& summary,
                                               const FB::variant& body,
                                               const FB::variant& icon)
{
    // Get the values passed
    std::string str_summary = summary.convert_cast<std::string>();
    std::string str_body = body.convert_cast<std::string>();
    std::string str_icon = icon.convert_cast<std::string>();

    // Retrieve the remote icon

    // Open a temp file
    std::ofstream of("/tmp/linuxnativenotification_image", std::ios::binary | std::ios::out);

    // Setup cURL
    CURL * g_curl = curl_easy_init();

    // Prepare space for storage of
    // error strings
    char error[CURL_ERROR_SIZE];

    // Now set the options we need
    curl_easy_setopt(g_curl, CURLOPT_URL, str_icon.c_str());
    curl_easy_setopt(g_curl, CURLOPT_HTTPGET, 1);
    curl_easy_setopt(g_curl, CURLOPT_ERRORBUFFER, error);
    curl_easy_setopt(g_curl, CURLOPT_WRITEFUNCTION, simple_callback);
    curl_easy_setopt(g_curl, CURLOPT_WRITEDATA, (void *)&of);

    // Now perform the fetch
    CURLcode code = curl_easy_perform(g_curl);

    if(code)

    #ifdef DEBUG
        return FB::variant(std::string(error));
    #else
        return FB::variant(false);
    #endif

    // Clean up cURL
    curl_easy_cleanup(g_curl);

    // Clean up the file
    of.close();

    // Create the notification
    NotifyNotification * pnote = notify_notification_new(str_summary.c_str(),
                                                         str_body.c_str(),
                                                         "/tmp/linuxnativenotification_image");

   // Try to append the notification
   if (str_summary == m_previous_summary)
      notify_notification_set_hint_string (pnote, "x-canonical-append", "true");

    m_previous_summary = str_summary;

    if (notify_notification_show(pnote, NULL) == FALSE)
        return FB::variant(false);

    return FB::variant(true);
}

///////////////////////////////////////////////////////////////////////////////
/// @fn LinuxNativeNotificationPtr LinuxNativeNotificationAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
LinuxNativeNotificationPtr LinuxNativeNotificationAPI::getPlugin()
{
    LinuxNativeNotificationPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}
