#include "ForwardChain.h"

ForwardChain::ForwardChain()
{
	traffic = question("Is there large amounts of traffic through your network or server?\n  ");
	if (traffic) {
		response = DDosPrevention();
	}
	else {
		functionality = question("\n\nHas your computers functionality been compromised ? \n(Y or y for yes, N or n for no) : ");
		if (functionality) {
			response = MalwarePrevention();
		}
		else {
			response = PhishingPrevention();
		}
	}
	std::cout << response;
}

std::string ForwardChain::DDosPrevention()
{
	allocatedResources = question("\nIs your server allocating as many resources as it can(max) for each request?	");
	if (allocatedResources) {
		return "Increase your server size or decrease the amount of resources allocated per request.";
	}

	pingTime = question("\nIs your server allocating as many resources as it can(max) for each request?	");
	if (pingTime) {
		return "Decrease your allowed time per Ping (set a maximum Ping time).";
	}

	IPRange = question("\nIs most of your traffic coming from the same IP address or the same IP range?	");
	if (pingTime) {
		return "Use a traffic identification system and/or block specific IP range's.";
	}

	// Last Resort 
	std::string ddos = "\nIf you still can't determine the issue or don't have any issues we recommend that you create a response ";
	ddos += "plan in case an attack ever happens and to search for any unknown weakness's in the code that may lead ";
	ddos += "to future issues.";
	return ddos;
}

std::string ForwardChain::PhishingPrevention()
{
	fakePerson = question("\nAre you concerned that an email that was sent to you wasn't sent by who it says it is?	");
	if (fakePerson) {
		return "\nConfirm in person that the email was actually sent from who it says it is.";
	}

	fakeLogin = question("\nAre you concerned that some one has your login information?	");
	if (fakeLogin) {
		return "\nReset your password, set up an authenticator, and never give out your information to anyone.";
	}

	spam = question("\nHas there been an increased amount of spam calls, emails, or texts?	");
	if (spam) {
		return "\nUse a spam identifier and blocker to reduce the number of calls, texts, and emails.";
	}
	linkFile = question("\nIs there a file(s) or link attached to an email or text from an unknown sender?	");
	if (linkFile) {
		return "\nDon't download any files from unknown senders and delete said email or text";
	}
	std::string phishing = "\nRemember to never give out your login information to anyone, even if its someone ";
	phishing += "you think you can trust. Also, try to always have two forms on authentication on your ";
	phishing += "account at all times! Stay safe, and stay vigilant.";

	return phishing;
}

std::string ForwardChain::MalwarePrevention()
{
	ads = question("\nDo ads keep appearing on your screen (in browser and out)?	");
	if (ads) {
		return "\nInstall or use an Ad blocker software.";
	}

	macros = question("\nDo you use a large amount of macro language systems such as Microsoft Word or Excel?	");
	if (macros) {
		return "\nDon't use or install macros from untrusted sources and enable programs to confirm macro use.";
	}

	website = question("\nAre you concerned about the safety of a website(s) you are visiting?	");
	if (website) {
		return "\nUse a secure browser and don't click on any suspicious ads or website pages.";
	}
	secret = question("\nAre you concerned there may be some downloads secretly happening on your system?	");
	if (secret) {
		return "\nInstall/Use a firewall and use/install a strong anti-virus software.";
	}
	infected = question("\nCan you locate the infected files?	");
	if (infected) {
		return "\nDelete the infected files you have found and run a security scan of your system.";
	}
	return "Un-install and re-install your anti-virus software or buy a better anti-virus software.";
}
