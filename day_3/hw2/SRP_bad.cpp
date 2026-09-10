#include <iostream>
#include <string>

// 사용자 정보
class User
{
private:
    std::string name;
    std::string email;
public:
    User(const std::string& name, const std::string& email)
        : name(name), email(email) {
    }

    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
};

// UserService : 저장 / 이메일 발송 / 로그 기록까지 모두 담당
class UserService
{
public:
    void saveUser(User& user)
    {
        // Save user to database
        std::cout << "User saved to database: " << user.getName() << std::endl;
    }

    void sendWelcomeEmail(User& user)
    {
        // Send welcome email to user
        std::cout << "Welcome email sent to: " << user.getEmail() << std::endl;
    }

    void logUserActivity(User& user)
    {
        // Log user activity
        std::cout << "Logging activity for user: " << user.getName() << std::endl;
    }
};

int main()
{
    User user("Alice", "alice@example.com");
    UserService service;

    service.saveUser(user);
    service.sendWelcomeEmail(user);
    service.logUserActivity(user);

    return 0;
}
