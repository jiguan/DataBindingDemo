#pragma once

using Windows::UI::Xaml::Data::ICustomProperty;

namespace DataBindingDemo
{
    namespace Common
    {
        /// <summary>
        /// Implementation of <see cref="INotifyPropertyChanged"/> to simplify models.
        /// </summary>
        [Windows::Foundation::Metadata::WebHostHidden]
        public ref class BindableBase : Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Data::INotifyPropertyChanged
        {
        public:
            virtual event Windows::UI::Xaml::Data::PropertyChangedEventHandler^ PropertyChanged;
            
        private:
            // ICustomPropertyProvider
            virtual ICustomProperty^ GetCustomProperty(Platform::String^ name);
            virtual ICustomProperty^ GetIndexedProperty(Platform::String^ name, Windows::UI::Xaml::Interop::TypeName type);
            virtual Platform::String^ GetStringRepresentation();

            property Windows::UI::Xaml::Interop::TypeName Type {
                virtual Windows::UI::Xaml::Interop::TypeName get() {
                    return this->GetType();
                }
            }

        protected:
            virtual void NotifyPropertyChanged(Platform::String^ propertyName);
        };
    }
    
}

