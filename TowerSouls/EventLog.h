#pragma once
#include <vector>
#include <iostream>
#include <string>

namespace GameLogic {




	/*
		Speichert alle Eventtexte
	*/
	class EventLog {
	private:
		// Enthaelt die Eventtexte
		std::vector<std::string> eventLog;
	public:
		// Legt einen neuen Eventlog an
		EventLog() {}

		//Rückgabe der Events		
		std::vector<std::string> getEventlog() { return eventLog; }
		//	Hinzufügen eines Eventtexts zum Eventlog
		void addEvent(std::string eventText) { eventLog.push_back(eventText); }
		void removeLast() { eventLog.pop_back(); }
		void clear() { eventLog.clear();}
	};

}