#pragma once
#include "Game.h"


void GameLogic::Game::handleStageSwitch(int stageValue) {
	int currentStage = this->player->getCurrentStage();
	Stage* stage = this->tower->getStage(currentStage);
	Point start = stage->getStart();
	this->player->setStart(start);
	if (stageValue < currentStage) 		
		this->player->setRoom(start);
	stage->getRoom(this->player->getRoom())->triggerEvent(this->player);
	stage->getRoom(this->player->getRoom())->reveal();
	this->view->draw(GameView::StageSwitch);
	Sleep(1500);
	this->view = new GameView::View(stage, this->player, this->log,this->beginStory);
}


bool GameLogic::Game::handleMove(GameLogic::direction d) {
	GameLogic::Stage* stage = this->tower->getStage(this->player->getCurrentStage());
	this->player->setSaveAble(false);

	int currStage = this->player->getCurrentStage();

	bool moved = this->player->move(d, stage);
	GameLogic::Room* movedTo = stage->getRoom(this->player->getRoom());
	movedTo->triggerEvent(this->player);	

	if (currStage != this->player->getCurrentStage())
		handleStageSwitch(currStage);
	
	return moved;
}

void GameLogic::Game::showTitle() {
	this->view = new GameView::View();
	this->view->draw(GameView::draw::Title);
	this->perspecitve = GameView::draw::Title;
}


void GameLogic::Game::initNewGame() {
		
	this->player = new Player();
	this->log = new EventLog();
	Stage* stage = this->tower->getStage(this->player->getCurrentStage());
	Point start = stage->getStart();
	this->player->setRoom(start);
	this->player->setStart(start);
	this->player->setLog(this->log);		
	this->initGameView(GameView::draw::Begin);
}



void GameLogic::Game::initGameView(GameView::draw p) {
	this->perspecitve = p;
	Stage* stage = this->tower->getStage(this->player->getCurrentStage());
	this->view = new GameView::View(stage, this->player, this->log, this->beginStory);	
	stage->getRoom(this->player->getRoom())->triggerEvent(this->player);		
	this->view->draw(this->perspecitve);
	this->active = true;
}

void GameLogic::Game::run(playerInput input ) {

	bool redraw = false;
	if (this->active) {
		switch (input) {
		case Left:
			this->log->clear();
			redraw = handleMove(West);
			break;
		case Right:
			this->log->clear();
			redraw = handleMove(East);
			break;
		case Up:
			this->log->clear();
			redraw = handleMove(North);
			break;
		case Down:
			this->log->clear();
			redraw = handleMove(South);
			break;
		case Help:
			if(this->perspecitve != GameView::Help)
				this->perspecitve = GameView::Help;
			else 
				this->perspecitve = GameView::Game;
			redraw = true;
			break;
		case Skip:
			if (this->perspecitve == GameView::Begin){
				this->perspecitve = GameView::Game;
				redraw = true;
			}
			else if(this->player->getWon())
				showTitle();					
			break;
		}
	}	
	
		
	if (redraw && this->perspecitve != GameView::draw::Title)
		this->view->draw(this->perspecitve);
	
}

void GameLogic::Game::setTower(Tower* tower) { 
	this->tower = tower; 
	this->beginStory = tower->getBeginStory();
	this->endStory = tower->getEndStory();
}