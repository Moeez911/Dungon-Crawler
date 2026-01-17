#pragma once
#pragma once

class String {
private:
    char data[50]; 
    int len;

public:
  
    String() 
    {
        data[0] = '\0';
        len = 0;
    }

  
    String(const char* input)
    {
        int i = 0;
        while (input[i] != '\0' && i < 49) 
        {
            data[i] = input[i];
            i++;
        }
        data[i] = '\0'; 
        len = i;
    }

  
    int length() 
    {
        return len;
    }

   
    char operator[](int index)
    {
        if (index >= 0 && index < len) 
        {
            return data[index];
        }
        return ' ';
    }

  
    bool operator==(const char* other) 
    {
        int i = 0;
        while (data[i] != '\0' && other[i] != '\0') 
        {
            if (data[i] != other[i])
            {
                return false;
            }
            i++;
        }
      
        return (data[i] == '\0' && other[i] == '\0');
    }

    const char* c_str() 
    {
        return data;
    }

    String& operator+=(const String& other) 
    {
        int i = 0;
       
        while (i < other.len && len < 49) 
        {
            data[len] = other.data[i];
            len++;
            i++;
        }
        data[len] = '\0';
        return *this;
    }

    String& operator+=(const char* other) 
    {
        int i = 0;
        while (other[i] != '\0' && len < 49)
        {
            data[len] = other[i];
            len++;
            i++;
        }
        data[len] = '\0';
        return *this;
    }
    friend String operator+(const String& lhs, const String& rhs) 
    {
        String result(lhs);
        result += rhs;
        return result;
    }

    friend String operator+(const String& lhs, const char* rhs)
    {
        String result(lhs);
        result += rhs;
        return result;
    }

    friend String operator+(const char* lhs, const String& rhs)
    {
        String result(lhs);
        result += rhs;
        return result;
    }
};