#include <iostream>
using namespace std;

// class Java
// {
// 	public:
// 		void header()
// 		{
// 			cout << "首页、公开课、登录、注册..." << endl;
// 		}
// 		void footer()
// 		{
// 			cout << "帮助中心、交流合作、站内地图..." << endl;
// 		}

// 		void left()
// 		{
// 			cout << "Java、Python、C++" << endl;
// 		}

// 		void content()
// 		{
// 			cout << "Java学科视频" << endl;
// 		}

// };
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册..." << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图..." << endl;
	}

	void left()
	{
		cout << "Java、Python、C++" << endl;
	}

	void content()
	{
		cout << "Java学科视频" << endl;
	}
};

class Java : public BasePage
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	}

};

void test01()
{
	cout << "Java下载视频页面如下：" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

}


int main()
{
	test01();
	return 0;

}
