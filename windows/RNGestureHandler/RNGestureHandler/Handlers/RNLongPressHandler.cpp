#include "pch.h"
#include "RNLongPressHandler.h"

using namespace winrt::RNGestureHandler;
using namespace winrt::Windows::UI::Input;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Input;

void RNLongPressGestureHandler::onHolding(winrt::Windows::Foundation::IInspectable const&,
    HoldingEventArgs const& e)
{
    VERBOSE_DEBUG("onHolding\n");

    RNGestureHandlerEventExtraData eventData;

    eventData.hasXY = true;
    eventData.x = e.Position().X;
    eventData.y = e.Position().Y;

    eventData.hasAbsoluteXY = true;
    eventData.absoluteX = e.Position().X;
    eventData.absoluteY = e.Position().Y;

    sendEventsInState(RNGestureHandlerState::Active, &eventData);
}

void RNLongPressGestureHandler::onPointerReleased(winrt::Windows::Foundation::IInspectable const& sender,
    winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e)
{
    RNGestureHandler::onPointerReleased(sender, e);

    sendEventsInState(RNGestureHandlerState::End, 0);
    sendEventsInState(RNGestureHandlerState::Undetermined, 0);
}