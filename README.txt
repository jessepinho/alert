Alert is an API module that introduces the drupal_set_message_for_user()
function. This function is identical in functionality to drupal_set_message(),
except that it allows your module to set a message for a given user, even if
the user is not the currently logged-in user. The message will be shown the
next time the user logs in or sends a request to your site.

It also introduces a number of other optional parameters that modules can use
as necessary. For example, modules can set a reference string to a particular
message, so that they can modify the message at a later time before it is shown
to the user.