#pragma once

using Windows::UI::Xaml::Input::ICommand;
using Windows::Foundation::EventHandler;
using Windows::Foundation::Metadata::WebHostHiddenAttribute;

namespace DataBindingDemo {
    namespace Common {
        public delegate void ExecuteDelegate(Platform::Object^ parameter);
        public delegate bool CanExecuteDelegate(Platform::Object^ parameter);

        [WebHostHidden]
        public ref class DelegateCommand sealed : public ICommand
        {
        public:
            virtual event EventHandler<Platform::Object^>^ CanExecuteChanged;

            DelegateCommand(void);
            DelegateCommand(ExecuteDelegate^ execute, CanExecuteDelegate^ canExecute);

            // Inherent from ICommand
            virtual void Execute(Platform::Object^ parameter) override;
            virtual bool CanExecute(Platform::Object^ parameter) override;
            void RaiseCanExecuteChanged();

        private:
            ExecuteDelegate^ m_executeDelegate;
            CanExecuteDelegate^ m_canExecuteDelegate;
            bool m_canExecute;
        };
    }
}
