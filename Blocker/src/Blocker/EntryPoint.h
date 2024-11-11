#pragma once
#ifdef BLCKR_PLATFORM_WINDOWS

extern Blocker::Application* Blocker::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Blocker::CreateApplication();
	app->Run();
	delete app;
}

#endif
