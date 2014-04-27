var osd = document.getElementById("notify-osd");
// console.log('Welcome to the background, go away.');

function chromifyRequest(request, sender, callback)
{
    // console.log("background");
    // Hint, it's always text.
    if( request.notificationType != 'HTML' )
    {
        osd.notify(request.title, request.body, request.iconUrl);
    }
};

chrome.runtime.onMessage.addListener(chromifyRequest);
chrome.runtime.onMessageExternal.addListener(chromifyRequest);