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
        : name(name), email(email) {}

    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
};

// UserRepository : 저장만 담당
class UserRepository
{
public:
    void saveUser(User& user)
    {
        // Save user to database
        std::cout << "User saved to database: " << user.getName() << std::endl;
    }
};

// EmailService : 이메일 발송만 담당
class EmailService
{
public:
    void sendWelcomeEmail(User& user)
    {
        // Send welcome email to user
        std::cout << "Welcome email sent to: " << user.getEmail() << std::endl;
    }
};

// UserActivityLogger : 로그 기록만 담당
class UserActivityLogger
{
public:
    void logUserActivity(User& user)
    {
        // Log user activity
        std::cout << "Logging activity for user: " << user.getName() << std::endl;
    }
};

int main()
{
    User user("Alice", "alice@example.com");

    UserRepository repository;
    EmailService emailService;
    UserActivityLogger logger;

    repository.saveUser(user);
    emailService.sendWelcomeEmail(user);
    logger.logUserActivity(user);

    return 0;
}
