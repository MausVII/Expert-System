#pragma once
#include "InputManager.h"
#include "KnowledgeBase.h"
#include <string>

class ForwardChain {
public:
	ForwardChain();
	std::string DDosPrevention();
	std::string PhishingPrevention();
	std::string MalwarePrevention();
private:
	std::string response;
	bool traffic;
	bool functionality;
	//	DDoS related variables
	bool allocatedResources;
	bool pingTime;
	bool IPRange;
	//	Malware related variables
	bool ads;
	bool macros;
	bool website;
	bool secret;
	bool infected;
	//	Phishing related variables
	bool fakePerson;
	bool fakeLogin;
	bool spam;
	bool linkFile;
};