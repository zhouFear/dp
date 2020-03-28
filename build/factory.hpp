#pragma once

/*
����ģʽ��Factory Pattern���� ��õ����ģʽ֮һ���������͵����ģʽ���ڴ�����ģʽ�����ṩ��һ�ִ����������ѷ�ʽ��

�ڹ���ģʽ�У������ڴ�������ʱ����Կͻ��˱�¶�����߼���������ͨ��ʹ��һ����ͬ�Ľӿ���ָ���´����Ķ���

����
��ͼ������һ����������Ľӿڣ����������Լ�����ʵ������һ�������࣬����ģʽʹ�䴴�������ӳٵ�������С�

��Ҫ�������Ҫ����ӿ�ѡ������⡣

��ʱʹ�ã�������ȷ�ؼƻ���ͬ�����´�����ͬʵ��ʱ��

��ν������������ʵ�ֹ����ӿڣ����ص�Ҳ��һ������Ĳ�Ʒ��

�ؼ����룺����������������ִ�С�

Ӧ��ʵ���� 1������Ҫһ������������ֱ�Ӵӹ������������������ȥ��������������ô�������ģ��Լ������������ľ���ʵ�֡� 2��Hibernate �����ݿ�ֻ�軻���Ժ������Ϳ��ԡ�

�ŵ㣺 1��һ���������봴��һ������ֻҪ֪�������ƾͿ����ˡ� 2����չ�Ըߣ����������һ����Ʒ��ֻҪ��չһ��������Ϳ��ԡ� 3�����β�Ʒ�ľ���ʵ�֣�������ֻ���Ĳ�Ʒ�Ľӿڡ�

ȱ�㣺ÿ������һ����Ʒʱ������Ҫ����һ��������Ͷ���ʵ�ֹ�����ʹ��ϵͳ����ĸ����ɱ����ӣ���һ���̶���������ϵͳ�ĸ��Ӷȣ�ͬʱҲ������ϵͳ��������������Ⲣ����ʲô���¡�

ʹ�ó����� 1����־��¼������¼���ܼ�¼������Ӳ�̡�ϵͳ�¼���Զ�̷������ȣ��û�����ѡ���¼��־��ʲô�ط��� 2�����ݿ���ʣ����û���֪�����ϵͳ������һ�����ݿ⣬�Լ����ݿ�����б仯ʱ�� 3�����һ�����ӷ������Ŀ�ܣ���Ҫ����Э�飬��POP3������IMAP������HTTP�������԰���������Ϊ��Ʒ�࣬��ͬʵ��һ���ӿڡ�

ע�������Ϊһ�ִ�����ģʽ�����κ���Ҫ���ɸ��Ӷ���ĵط���������ʹ�ù�������ģʽ����һ����Ҫע��ĵط����Ǹ��Ӷ����ʺ�ʹ�ù���ģʽ�����򵥶����ر���ֻ��Ҫͨ�� new �Ϳ�����ɴ����Ķ�������ʹ�ù���ģʽ�����ʹ�ù���ģʽ������Ҫ����һ�������࣬������ϵͳ�ĸ��Ӷȡ�

*/
#include <stdio.h>
class ProductBase
{
public:
	ProductBase() = default;
	virtual ~ProductBase() {};
public:
	virtual void doSomething() = 0;
private:

};


class ProductA :public ProductBase
{
public:
	ProductA() :ProductBase() {};
	~ProductA() {};
public:
	void doSomething() override {
		printf("ProductA::doSomething\n");
	};
private:

};

class ProductB :public ProductBase
{
public:
	ProductB() :ProductBase() {};
	~ProductB() {};
public:
	void doSomething() override {
		printf("ProductB::doSomething\n");
	};
private:

};

class FactoryBase
{
public:
	FactoryBase() = default;
	virtual ~FactoryBase() {};

public:
	virtual ProductBase* createProduct() = 0;
};


class FactoryA : public FactoryBase
{
public:
	FactoryA():FactoryBase() {
	};
	~FactoryA() {};

public:
	ProductBase* createProduct() override {
		return new ProductA();
	};
};


class FactoryB : public FactoryBase
{
public:
	FactoryB() :FactoryBase() {
	};
	~FactoryB() {};

public:
	ProductBase* createProduct() override {
		return new ProductB();
	};
};