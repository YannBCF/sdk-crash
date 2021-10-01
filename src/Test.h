#pragma once

#include "main.h"

void Test() {
	alt::ICore::Instance().SubscribeEvent(alt::CEvent::Type::PLAYER_CONNECT, [](const alt::CEvent* ev, void* userData)
	{
        auto& core = alt::ICore::Instance();
	    auto event = static_cast<const alt::CPlayerConnectEvent*>(ev);
	    auto player = event->GetTarget();

        alt::MValueArgs args;
        auto boolean = core.CreateMValueBool(true);
        args.Push(boolean);

        Log::Info << "TEST <<" << Log::Endl;
        core.TriggerClientEvent(player, "test", args);
	    return true;
	});
}