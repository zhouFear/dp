// dm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


#include "./build/Factory.hpp"
#include "./build/prototype.hpp"

#include "./construction/proxy.hpp"
#include "./construction/decorator.hpp"

#include "./behaviour/templatemethod.hpp"
#include "./behaviour/strategy.hpp"

using namespace std;

int main()
{
    //工厂模式
    if (0) {
        cout << "工厂模式" << endl;
        shared_ptr<FactoryBase> fa = make_shared<FactoryA>();
        shared_ptr<ProductBase> A(fa->createProduct());
        A->doSomething();

        shared_ptr<FactoryBase> fb = make_shared<FactoryB>();
        shared_ptr<ProductBase> B(fb->createProduct());
        B->doSomething();
    }

    // 原型模式
    if (0) {
        cout << "原型模式" << endl;
        shared_ptr<IClone> A = make_shared<ConcretePrototypeA>();
        shared_ptr<IClone> B(A->clone());

        A->show();
        B->show();
    }

    // 代理模式
    if (1) {
        cout << "代理模式" << endl;
        shared_ptr<Proxy> pProxy = make_shared<Proxy>();
        pProxy->request();
    }

    // 装饰模式
    if(0)
    {
        cout << "装饰模式" << endl;
        shared_ptr<Component> cc(new ConcreteComponent());
        shared_ptr<Decorator> A(new ConcreteDecoratorA());
        shared_ptr<Decorator> B(new ConcreteDecoratorB());
        A->setComponent(cc.get());
        B->setComponent(A.get());
        B->Operation();
    }


    // 模板方法模式
    if(0)
    {
        cout << "模板方法模式" << endl;
        shared_ptr<TemplateMethodBase> A = make_shared<MethodA>();
        shared_ptr<TemplateMethodBase> B = make_shared<MethodB>();
        A->templateMethod();
        B->templateMethod();
    }

    // 策略模式
    if (1) {
        cout << "策略模式" << endl;
        shared_ptr<Context> spContextA = make_shared<Context>(0);
        spContextA->doSomething(100);

        shared_ptr<Context> spContextB = make_shared<Context>(1);
        spContextB->doSomething(100);
    }
    
}

