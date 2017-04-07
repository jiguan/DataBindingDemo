#include "pch.h"
#include "BindableBase.h"

using namespace DataBingingDemo::Common;

using Platform::String;
using Windows::UI::Xaml::Interop::TypeName;
using Windows::UI::Xaml::Data::ICustomProperty;
using Windows::UI::Xaml::Data::PropertyChangedEventArgs;

/// <summary>
/// Notifies listeners that a property value has changed.
/// </summary>
/// <param name="propertyName">Name of the property used to notify listeners.</param>
void BindableBase::NotifyPropertyChanged(String^ propertyName)
{
    PropertyChanged(this, ref new PropertyChangedEventArgs(propertyName));
}

ICustomProperty^ BindableBase::getCustomProperty(String^ name)
{
    return nullptr;
}

ICustomProperty^ BindableBase::getIndexedProperty(String^ name, TypeName type)
{
    return nullptr;
}

String^ BindableBase::getStringRepresentation() 
{
    return this->ToString();
}