//
//  File: Game.cpp
//  Author: Jiwon Jung (devziwon@gmail.com)
//
//  Copyright (c) 2023 Jiwon Jung. All rights reserved.
//

#include "pch.h"
#include "Game.h"
#include "Engine.h"

void Game::Init(const WindowInfo& info)
{
	GEngine->Init(info);
}

void Game::Update()
{
	GEngine->Render();
}
