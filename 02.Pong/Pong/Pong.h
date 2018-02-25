#pragma once
#include <SDL.h>
#include "Ball.h"
#include "Player.h"
#include "SerialInterface.h"
#include "../engine/Singleton.h"
#include "../engine/StateMachine.h"

class Pong : public Singleton<Pong>
{		
	public:
		SerialInterface* serialInterface;

		Player ThePlayers[2];
		Ball TheBall;
		Player::Side lastScore;

		bool OnOneTimeInit();
		void OnNewGame();
		int Score[2];
		bool Init();
		bool Update();
		bool Draw();
		void clean();
		bool Shutdown();	

		StateMachine stateMachine;

		Player& GetPlayer(Player::Side side);
		Ball& GetBall();

		void DrawCourt();
		void DrawPlayers();
		void DrawBall();
		void DrawScore();

		void UpdateScore();
		bool IsBallOut();
		bool IsGameOver();
		Player::Side  GetWhichPlayerScored();
		Player::Side  GetPlayerToServe();

private:
	
	};