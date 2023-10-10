#pragma once

#include <utility>

#include "Core.hpp"
#include "Events/Event.hpp"

namespace HazelPVR
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		explicit WindowProperties(std::string title = "HazelPVR Engine",
                         unsigned int width = 2160,
                         unsigned int height = 1350)
			: Title(std::move(title)), Width(width), Height(height)
		{}
	};

	// Interface representing a desktop system based Window
	class HAZELPVR_API Window
	{
		public:
			using EventCallbackFn = std::function<void(Event&)>;

			virtual ~Window() = default;

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			// Window attributes
			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			virtual void* GetNativeWindow() const = 0;

			static Window* Create(const WindowProperties& properties = WindowProperties());
	};
}