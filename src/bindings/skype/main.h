#ifndef __MAIN_H__
#define __MAIN_H__

#include <vector>
#include <string>

namespace YAMM
{
// start up daemons
/**
 * Initialization function. Every library must provide an intialization fucntion that prepares the library for use. Consider starting up daemons, logging in etc.
 * @param error callback to a function taking string returning void, to output error messages etc.
 * @param receiveMessage callback to a function taking string returning void, to output error messages etc. receiveMessage will be call whenever an error occours, i.e. it will be saved for later use.
 * @version pre-alpha
 * @date: 17.03.2012
 */
bool init(std::string username, std::string password, void (*error)(std::string msg), void (*receiveMessage)(std::string user, std::string msg));

// personal information

struct user
{
    std::string firstName, lastName;
    std::string phoneNumber;
};

user getUserInformation();

// person's environment
std::vector<std::string> getPersonsFriends();

// helper function
int getUserID(std:.string user)

// interaction with other users
bool sendMessage(int user, std::string message);
bool

// shut down daemons
bool finalize();
}
#endif // __MAIN_H__
