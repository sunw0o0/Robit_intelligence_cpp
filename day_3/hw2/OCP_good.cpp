#include <iostream>
#include <memory>
#include <vector>

//순수 가상 함수로 구현
class Report
{
public:
    virtual void generate() = 0;
    virtual ~Report() {}
};

class PDFReport : public Report
{
public:
    void generate() override
    {
        std::cout << "Generating PDF report..." << std::endl;
    }
};

class HTMLReport : public Report
{
public:
    void generate() override
    {
        std::cout << "Generating HTML report..." << std::endl;
    }
};

// 새로운 포맷 추가 시 기존 클래스는 전혀 수정하지 않음
class XMLReport : public Report
{
public:
    void generate() override
    {
        std::cout << "Generating XML report..." << std::endl;
    }
};

int main()
{
    std::vector<std::unique_ptr<Report>> reports;
    reports.push_back(std::make_unique<PDFReport>());
    reports.push_back(std::make_unique<HTMLReport>());
    reports.push_back(std::make_unique<XMLReport>());

    for (auto& report : reports)
    {
        report->generate();
    }

    return 0;
}
