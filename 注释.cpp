/*
 * @Author: LiunxPaisley 
 * @Date: 2017-04-27 15:44:13 
 * @Last Modified by: LiunxPaisley
 * @Last Modified time: 2017-04-27 15:44:39
 */

/**
* 						_ooOoo_
* 					   o8888888o
* 					   88" . "88
*                      (| -_- |)
*                       O\ = /O
*                   ____/`---'\____
*                    .' \\| |// `.
*                  / \\||| : |||// \
*                / _||||| -:- |||||- \
*                |   | \\\ - /// |   |
*                | \_| ''\---/'' |   |
*                 \ .-\__ `-` ___/-. /
*              ___`. .' /--.--\ `. . __
*           ."" '< `.___\_<|>_/___.' >'"".
*		   | | : `- \`.;`\ _ /`;.`/ - ` : | |
*           \  \ `-. \_ __\ /__ _/ .-`   /  /
*    ======`-.____`-.___\_____/___.-`____.-'======
*                       `=---='
* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*                   佛祖保佑 永无BUG
*
*                  佛曰:
*              写字楼里写字间，写字间里程序员；
*              程序人员写程序，又拿程序换酒钱。
*              酒醒只在网上坐，酒醉还来网下眠；
*              酒醉酒醒日复日，网上网下年复年。
*              但愿老死电脑间，不愿鞠躬老板前；
*              奔驰宝马贵者趣，公交自行程序员。
*              别人笑我忒疯癫，我笑自己命太贱；
*              不见满街漂亮妹，哪个归得程序员？
*/
#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <algorithm>
#include <queue>
#include <memory>
using namespace std;

int main()
{
	/*输出1*/
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << (((i + j - 8) * (i - j) >= 0) ? "*" : " ");
		}
		cout << endl;
	}

	vector<int> v = {2, 3, 6, 1, 5, 7, 8, 9};
	std::partial_sort(v.begin() + 1, v.begin() + 4, v.end());
	for (int var : v)
	{
		cout << var << " ";
	}
	cout << endl;

	int n = 5;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n; j++)
		{
			cout << (((j >= n - i - 1) && (j <= 2 * n - i - 1)) ? ((j > n - 1) ? 'B' : 'A') : ' '); // (abs(j - n + 1) < i)[" AB "]
		}
		cout << endl;
	}
}