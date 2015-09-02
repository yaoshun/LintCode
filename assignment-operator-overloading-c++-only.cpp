// LintCode operator overloading example

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        // Check whether they are the same object.
        // this is a pointer.
        if (this != &object) {
            char *new_pData = NULL;
            if (object.m_pData != NULL) {
                size_t cnt = strlen(object.m_pData);
                new_pData = new char[cnt];
                copy(object.m_pData, object.m_pData + cnt, new_pData);
            }
            
            if (m_pData != NULL)
                delete m_pData;
            
            m_pData = new_pData;
        }
        
        // Return the Solution object.
        return *this;
    }
};

// Solution 2 using malloc instead of new char[cnt].
// using memcpy instead of std::copy.
class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        // Check whether they are the same object.
        // this is a pointer.
        if (this != &object) {
            char *new_pData = NULL;
            if (object.m_pData != NULL) {
                size_t cnt = strlen(object.m_pData);
                new_pData = (char*)malloc(cnt + 1);
                memcpy(new_pData, object.m_pData, cnt);
                new_pData[cnt] = '\0';
            }

            if (m_pData != NULL)
                delete m_pData;

            m_pData = new_pData;
        }

        // Return the Solution object.
        return *this;
    }
};

