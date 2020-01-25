#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//int main()
//{
//	vector<int> v1;
//	vector<int> v2(10,5);
//	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
//	vector<int> v3(array,array+sizeof(array)/sizeof(int));
//	vector<int> v4(v3);
//
//	v1 = v2;
//	return 0;
//}
#if 0
int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,0 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	//auto it = v.begin();
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	v.resize(20, 9);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(10);//�������������0
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.reserve(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(100);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	return 0;
	
}
#endif
#if 0
//������[ )
#include<string>
int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,0 };
	cout << v.front() << endl;
	cout << v.back() << endl;

	//++��������begin--->end�����ƶ�
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int>::reverse_iterator it2 = v.rbegin();
	while (it2 != v.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	v.insert(v.begin(), 0);
	cout << v[5] << endl;
	//at �� operator[]�������ǵ�һ�������쳣���ڶ����Ƕ���
	/*cout << v[100] << endl;
	cout << v.at(100) << endl;*/
	v.assign(10, 5);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	string s("hello");
	vector<char> vv;
	vv.assign(s.begin(), s.end());


	return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
int main()
{
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	//foo.reserve(100);
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	return 0;
}
#endif
#include<algorithm>
//������ʧЧ����
int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,0 };
	auto it = v.begin();

	v.push_back(1);//���������

	sort(v.begin(), v.end());
	it = v.begin();//���¸�ֵ���������ʧЧ

	while (it != v.end())//itָ��֮ǰ���������Ե�����ʧЧ
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	it = v.begin();
	while (it != v.end())
	{
		it = v.erase(it);
		//it++;
	}
	return 0;
}
//string:
//vector<char>
//�ֿ���ԭ����� ��ͬ���������ͣ����о���vectorû��'\0'  ���ά���Ļ������Ͳ���ʵ������������
//1.����
//�չ��캯��
//n��ֵdataԪ�صĹ���
//���乹��
//��������
//2.��������
//size() capacity() empty()
//resize(newSize,data):��vector����ЧԪ�ظ������µ�newSize
//reserve(newCapacity):ΪvectorԤ���ռ䣬ע�⣺����ı���ЧԪ�صĸ���
//newCapacity <= oldCapacity ������
//newCapacity > oldCapacity: �����Ľ�������  SGI��
//3.Ԫ�ط��ʣ�
//T& operator[](size_t index) / const T& operator[](size_t index)const;
//at
//T& front() / const T& front()const
//T& back() / const T& back() const
 //4.�޸�
//5.������ ����Ҫ�ṩ���㷨��ʹ�õ�
//���㷨����͸���������ù��ĵײ�����ݽṹ���Ĳ�������
//begin()/end()--->[begin,end) ���������
//rbegin() / rend()--->[rbegin,rend) ���������
//������ʧЧ��
//vector�еĵ����������ͣ�typedef T* iterator;
//auto it = v.begin(); itʵ���Ѿ�ָ��vector�ײ�ռ����ʼλ��
//v.push_back(data);
//ͨ��it����������vector�е�Ԫ��--->���ܻ�����������
//1.����ײ�ռ�ĸı�---push_back/insert resize/reserve swap assign
//2.erase(pos)--pos�ĵ�����ʧЧ pos-->vector�е�ĳ��λ��-->T���Ͷ���
//���������ʧЧ
//�����������¸�ֵ

// �����ĵ�����ʧЧ�ĳ���
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ʵ��ɾ��v�е�����ż��
	// ����ĳ����������������ż����erase����itʧЧ
	// ��ʧЧ�ĵ���������++it���ᵼ�³������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
			++it;
	}
	// ���ϳ���Ҫ�ĳ�����������erase�᷵��ɾ��λ�õ���һ��λ��
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	return 0;
}