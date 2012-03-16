#ifndef __MAIN_H__
#define __MAIN_H__

#include <vector>

namespace YAMM
{
// start up daemons
/// @arg error is a callback to a function taking string returning void, to output error messages etc.
/// @arg receiveMessage is a callback to a function taking string returning void, to output error messages etc.
bool init(std::string username, std::string password, void (error*)(std::string msg), void (receiveMessage*)(std::string user, std::string msg));

// personal information

struct person
{
    std::string firstName, lastName;
    std::string phoneNumber;

} getPersonalInformation();

// person's environment
vector<string> getPersonsFriends();

// interaction with other users
bool sendMessage(std::string user, std::string message);

// shut down daemons
bool finalize();
}
#endif // __MAIN_H__
