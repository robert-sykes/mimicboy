#ifndef REGISTER_H
#define REGISTER_H

namespace MimicBoy {
    template<typename T>
    class Register {
        /**
         * @brief Represents a generic container for a value.
         *
         * This variable is a template instance which can hold a value of any type.
         * The specific type of the value is determined at compile time when
         * the variable is instantiated.
         */
    private:
        T value;
        /**
         * Default constructor for the Register class.
         * Initializes the value to 0.
         *
         * @return An instance of the Register class with value set to 0.
         */
    public:
        Register() : value(0) {}
        explicit Register(T val) : value(val) {}

        /**
         * Retrieves the stored value.
         *
         * @return The current value of type T.
         */
        T getValue() const { return value; }
        /**
         * Sets the value of the object.
         *
         * @param val The value to set of type T.
         */
        void setValue(T val) { this->value = val; }

        Register<T>& operator++() { ++value; return *this; }
        Register<T> operator++(int) { Register<T> temp = *this; ++value; return temp; }

        Register<T>& operator--() { --value; return *this; }
        Register<T> operator--(int) { Register<T> temp = *this; --value; return temp; }

        Register<T>& operator=(T val) { value = val; return *this; }

        Register<T>& operator|=(T val) { value |= val; return *this; }
        Register<T>& operator&=(T val) { value &= val; return *this; }
        Register<T>& operator^=(T val) { value ^= val; return *this; }

        bool operator==(T val) const { return value == val; }
        bool operator!=(T val) const { return value != val; }
    };
}

#endif //REGISTER_H
