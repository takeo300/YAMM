class Message{
QDate sent;
User from;
Chat to;
std::string what;
}

/// Container für zusammengemergte Chats / Calls
struct Conversation{
	Chat[] chats;
	Call[] calls;
};

/// Informationen + Inhalt eines Chats
struct Chat{
	/// Nachrichten
	Message[] messages;
	/// Mitglieder des Chats
	User[] members;
	/// vielleicht optional, für Skype wichtig: Besitzer des Chats
	/// @TODO: optional: Wie bekommen wir das in eine Form?
	/// @TODO: Rollenverteilung innerhalb des Chats? Admin, Creator, Listener etc.?
	User owner;
};

/// Informationen über einen Anruf
struct Call{
	/// Mitglieder des Anrufs
	User[] members;
	/// vergangene Zeit in Millisekunden
	unsigned long timeElapsed;
	/// vielleicht optional, für Skype wichtig: Besitzer des Anrufs
	User owner;
};

class Connection{
	/// Verbindung herstellen
	virtual void connect() = 0;
	/// Verbindung trennen
	virtual void disconnect() = 0;
};

class IMConnection: public Connection{
/// @return Gesendete Nachricht als @see Message
	virtual void Message send(String msg) = 0;
public signals:
	msgReceived(Message msg);
};

class CallConnection: public Connection{
/// Führt einen Anruf an die übergebenen Benutzer aus.
/// @return Anruf als @see Call.
	Call doCall(User[] users) = 0;
/// Beantwortet den übergebenen Anruf bzw. entfernt das Halten.
/// @todo Differenzierung zwischen Anruf beantwortet / halten?
	Call doCall(Call call) = 0;
/// Stumm schalten bzw. Stummschaltung aufheben	
	void setSilent(bool silent = true);
signals:
	callReceived(Call call);
};

class IMCallConnection : public IMConnection, CallConnection
{
/// Wenn sowohl IMs als auch Calls gehalten werden können, können aus beiden Typen bestehende Conversations verwandt werden.
Conversation[] conversations;
}
/// @todo Können wir davon ausgehen, dass ein VideoCall ein Call ist?
class VideoCallConnection: public CallConnection
{
/// Stumm schalten bzw. Stummschaltung aufheben	
	void setSilent(bool silent = true);
/// Videoübertragung de-/aktivieren.
	void setVideoEnabled(bool enabled = true);
/// Führt einen Videoanruf an die übergebenen Benutzer aus.
/// @return Anruf als @see Call.
	Call doVCall(User[] users) = 0;
/// Beantwortet den übergebenen Videoanruf bzw. entfernt das Halten.
/// @todo Differenzierung zwischen Anruf beantwortet / halten?
	Call doVCall(Call call) = 0;	
signals:
	vCallReceived(Call call);
};

class GUI{
public slots:
	receiveCall(Call call);
	receiveVCall(Call call);
	receiveMsg(Message msg);
};

class Skype: Connection, IMCallConnection, VideoCallConnection{
/// Skype's eigener Brei!
void SkypeSpecificFunction();
};

