// STEP 1: Inject page.js into the actual page's DOM so we can interact with said page

var s = document.createElement("script");
s.src = chrome.extension.getURL("page.js");
s.type = "text/javascript";
document.getElementsByTagName("head")[0].appendChild(s);

// STEP 2: ????

document.addEventListener("chromifyOSDComEvent", function(e)
{
    var event_data = document.getElementById("chromifyOSDComObject");
    var title = event_data.firstChild.innerHTML;
    var body = event_data.firstChild.nextSibling.innerHTML;
    var iconUrl = event_data.firstChild.nextSibling.nextSibling.innerHTML;
    var notificationType = event_data.firstChild.nextSibling.nextSibling.nextSibling.innerHTML;
    event_data.parentNode.removeChild(event_data);

    // console.log(title, body, iconUrl, notificationType);
    // console.log(chrome.runtime.id);
    chrome.runtime.sendMessage(chrome.runtime.id,
    {
        title: title, body: body, iconUrl: iconUrl, notificationType: notificationType
    },
    function(response)
    {
        // console.log(response);
        // do something, or nothing, depending on the response from background.html
    });
});

// STEP 3: PROFIT!!
