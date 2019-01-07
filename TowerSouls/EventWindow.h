#pragma once
#include <iostream>
#include "EventLog.h"
#include "ViewUtils.h"
#include <iomanip>

namespace GameView {
	/*
		Rendert das Eventfenster unter der Map
	*/
	class EventWindow {
	private:		
		// Die Verschiebung des Fensters nach rechts
		unsigned int spacer;
		unsigned int size;
		void frame();
		void content(std::string text);
		GameLogic::EventLog* log;
	public:
		// Legt ein neues Eventfenster mit Verschiebung von links an
		EventWindow(int nSpacer, GameLogic::EventLog* Log) : spacer(nSpacer), size(150), log(Log) {}
		// Zeichnet das Eventfenster auf der Konsole
		void draw();
	};
}