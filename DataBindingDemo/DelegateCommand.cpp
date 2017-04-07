#include "pch.h"
#include "DelegateCommand.h"

using Platform::String;
using namespace DataBindingDemo::Common;

DelegateCommand::DelegateCommand() {}

DelegateCommand::DelegateCommand(ExecuteDelegate^ execute, CanExecuteDelegate^ canExecute) : m_executeDelegate(execute), m_canExecuteDelegate(canExecute) {}

 void DelegateCommand::Execute(Object^ parameter) 
{
    if (m_executeDelegate) {
        m_executeDelegate(parameter);
    }
}

bool DelegateCommand::CanExecute(Object^ parameter)
{
    if (m_canExecuteDelegate) {
        return m_canExecuteDelegate(parameter);
    }
    return true;
}

void DelegateCommand::RaiseCanExecuteChanged()
{
    CanExecuteChanged(nullptr, nullptr);
}
