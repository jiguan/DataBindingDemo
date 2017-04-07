#pragma once

#include "BindableBase.h"
#include <collection.h>

using namespace DataBindingDemo::Common;

using Platform::String;
using Platform::Collections::Vector;
using Windows::UI::Xaml::Input::ICommand;
using Windows::UI::Xaml::Data::BindableAttribute;
using Windows::UI::Xaml::Controls::Button;
using Windows::Foundation::Collections::IVector;

namespace DataBindingDemo {
    [Bindable]
    public ref class NameValuePair sealed : BindableBase
    {
    public:
        NameValuePair(String^ name, String^ value)
        {
            Name = name;
            Value = value;
        }
        property String^ Name {
            String^ get() { return _name; }
            void set(String^ value) {
                _name = value;
                NotifyPropertyChanged("Name");
            }
        }

        property String^ Value {
            String^ get() { return _value; }
            void set(String^ value) {
                _value = value;
                NotifyPropertyChanged("Value");
            }
        }

    private:
        String^ _name;
        String^ _value;
    };

    [Bindable]
    public ref class MainViewModel sealed : public BindableBase
    {
    public:
        MainViewModel(void);
        void Initialize();
        void Execute(Object^ parameter); 
        bool CanExecute(Object^ parameter);

        property ICommand^ buttonCommand;

        property bool checkBox1 {
            bool get() { 
                return _checkBox1; 
            }
            void set(bool value) {
                _checkBox1 = value;
                NotifyPropertyChanged("checkBox1");
            }
        }

        property bool checkBox2 {
            bool get() {
                return _checkBox2;
            }
            void set(bool value) {
                _checkBox2 = value;
                NotifyPropertyChanged("checkBox2");
            }
        }

        property String^ statusResult {
            String^ get() {
                return _statusResult;
            }
            void set(String^ value) {
                _statusResult = value;
                NotifyPropertyChanged("statusResult");
            }
        }

        property IVector<NameValuePair^>^ nameValueList {
            IVector<NameValuePair^>^ get() {
                return _nameValueList;
            }
            void set(IVector<NameValuePair^>^ value) {
                _nameValueList = value;
                NotifyPropertyChanged("nameValueList");
            }
        }

        property NameValuePair^ selectedNameValue
        {
            NameValuePair^ get() { return _selectedNameValue; }
            void set(NameValuePair^ value) { 
                _selectedNameValue = value;
                NotifyPropertyChanged("selectedNameValue");
            }
        }

    private:
        bool _checkBox1;
        bool _checkBox2;
        String^ _statusResult;
        String^ _selectedValue;
        NameValuePair^ _selectedNameValue;
        IVector<NameValuePair^>^ _nameValueList;
    };


}


