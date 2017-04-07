#include "pch.h"
#include "MainViewModel.h"
#include "DelegateCommand.h"

using DataBindingDemo::MainViewModel;
using DataBindingDemo::Common::BindableBase;

// Helper template - RaiseCanExecuteChanged is a method on 
// DelegateCommand and is not available on ICommand.  We'll cast 
// instance to T and then call RaiseCanExecuteChanged which will 
// force each Command::CanExecute() to be called
template <typename T>
static void RaiseCanExecuteChange(ICommand^ instance)
{
    auto command = dynamic_cast<T^>(instance);
    command->RaiseCanExecuteChanged();
}

MainViewModel::MainViewModel(void) {}

void MainViewModel::Initialize()
{
    buttonCommand = ref new DelegateCommand(ref new ExecuteDelegate(this, &MainViewModel::Execute),
        ref new CanExecuteDelegate(this, &MainViewModel::CanExecute));

    NotifyPropertyChanged("buttonCommand");

    auto list = ref new Vector<NameValuePair^>();
    list->Append(ref new NameValuePair("Name1", "Value1"));
    list->Append(ref new NameValuePair("Name2", "Value2"));
    list->Append(ref new NameValuePair("Name3", "Value3"));
    list->Append(ref new NameValuePair("Name4", "Value4"));

    // Set list and selected (notify event will fire)
    nameValueList = list;
    selectedNameValue = list->GetAt(0);
}

void MainViewModel::Execute(Object^ parameter)
{
    auto button = dynamic_cast<Button^>(parameter);

    if (button->Name == "btnReset")
    {
        OutputDebugString(L"Reset button click\n");
        checkBox1 = false;
        checkBox2 = false;
        statusResult = "Checkboxes reset to false";
    }

    if (button->Name == "btnDisplay")
    {
        auto comboName = selectedNameValue->Name;
        auto comboValue = selectedNameValue->Value;

        statusResult = "CheckBox1=" + checkBox1.ToString()
                        + "\tCheckBox2=" + checkBox2.ToString()
                        + "\r\nCombo Name=" + comboName
                        + "\tValue=" + comboValue;
    }
}

bool MainViewModel::CanExecute(Object^ parameter)
{
    auto button = dynamic_cast<Button^>(parameter);

    if (button->Name == "btnDisplay")
        return true;

    // Only enable if one of the checkboxes is checked
    return checkBox1 || checkBox2;
}

