#ifndef __MAIN_H__
#define __MAIN_H__

#include <vector>
#include <string>

enum Error
{
    NoError;
}

namespace YAMM
{
/**
 * Initialization function. Every library must provide an intialization function that prepares the library for use. Consider starting up daemons, logging in etc. A bunch of function pointer should ensure the basic ommunication between library and calling program.
 * @param error callback to a function taking a string and an errorID returning void, to output error messages etc.
 * @param receiveMessage callback to a function taking string returning void, to output error messages etc. receiveMessage will be call whenever an error occours, i.e. it will be saved for later use.
 * @version pre-alpha
 * @date: 17.03.2012
 * @return true, if successful, false if not. Before the functions returns false, it will call the function associated with the function pointer error.
 * @see Error
 */
bool init(std::string username, std::string password, void (*error)(Error errorID, std::string msg), void (*receiveMessage)(std::string user, std::string msg));

// personal information

struct User
{
    std::string firstName; /// first name
    std::string lastName; /// last name
    std::string phoneNumber; /// phone number
};

struct Message{
    std::string content; /// content
    unsigned int sender; /// sender
    unsigned int receiver; /// receiver
    /// @todo add date
}

// person's environment
std::vector<std::string> getPersonsFriends();

// helper functions
/**
 * Gets a UserID of a contact.
 * @param user contact
 * @return: unique int that identifies the specified user
 * @date: 17.03.2012
 * @version : pre-alpha
 */
unsigned int getUserID(std::string user);

/**
 * Gets a ConversationID of a conversation
 * @param conversation conversation
 * @return: unique int that identifies the specified conversation
 * @date: 17.03.2012
 * @version : pre-alpha
 */
unsigned int getConversationID(std::string converstion);

/**
 * Get message history for the specified user.
 * @param conversation id of the conversation. @see getConversationID
 * @return a vector containing every message sent in the specified conversation
 * @date: 17.03.2012
 * @version : pre-alpha
/// @todo date missing
 */
std::vector<std::string> getMessageHistory(unsigned int conversation);

/**
 * Send a text message in the specified conversation
 * @param id of the conversation. @see getConversationID.
 * @date: 17.03.2012
 * @version : pre-alpha
 */
user getUserInformation();

// interaction with other users
/**
 * Send a text message to the specified user.
 * @param id of the receiver. @see getUserID.
 * @param message message
 * @date: 17.03.2012
 * @version : pre-alpha
 */
bool sendMessage(int user, std::string message);

/**
 * Call the specified user.
 * @param id of the receiver. @see getUserID.
 * @param video specifies, whether the transmission is a video or a audio-only transmission. Audio-only transmission by default.
 * @date 17.03.2012
 * @version pre-alpha
 */
bool makeCall(int user, boot video = false);

/**
 * De/-Activates the video transmission. CARE! Function will fail, if there is no active call.
 * @param videoOn videotransmission is activated if videoOn is true. Otherwise, it will be disabled.
 * @date 17.03.2012
 * @version pre-alpha
 */
bool changeVideo(bool videoOn);

/**
 * Terminates the active call. As only one call may be active at the same time, no specification concerning the user is necessary.
 * @date 17.03.2012
 * @version pre-alpha
 * @return true, if the call could be terminated, false if not.
 */
bool terminateCall();

// shut down daemons
/**
 * Finalization function. Every library must provide an intialization fucntion that shuts the library down. Consider shutting down daemons, logging off etc.
 * @version pre-alpha
 * @date 17.03.2012
 * @return true, if successfull, false if not. Before the function fails, it will call the function associated with the function pointer error.
 */
bool finalize();
}
#endif // __MAIN_H__
