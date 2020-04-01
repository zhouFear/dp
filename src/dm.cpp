// dm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


#include "./build/Factory.hpp"
#include "./build/prototype.hpp"
#include "./build/builder.hpp"

#include "./construction/proxy.hpp"
#include "./construction/decorator.hpp"
#include "./construction/facade.hpp"

#include "./behaviour/templatemethod.hpp"
#include "./behaviour/strategy.hpp"
#include "./behaviour/state.hpp"

using namespace std;

State::State* State::ConcreteStateA::instance = nullptr;
State::State* State::ConcreteStateB::instance = nullptr;

int main()
{
    //工厂模式
    if (0) {
        cout << "工厂模式" << endl;
        auto fa = make_shared<FactoryA>();
        shared_ptr<ProductBase> A(fa->createProduct());
        A->doSomething();

        auto fb = make_shared<FactoryB>();
        shared_ptr<ProductBase> B(fb->createProduct());
        B->doSomething();
    }

    // 原型模式
    if (0) {
        cout << "原型模式" << endl;
        auto A = make_shared<ConcretePrototypeA>();
        shared_ptr<IClone> B(A->clone());

        A->show();
        B->show();
    }

    // 创建者模式
    if (1)
    {
        cout << "创建者模式" << endl;
        auto spd = make_shared<Director>();
        shared_ptr<BuilderBase> bb = make_shared<BuildBenze>();
        shared_ptr<BuilderBase> fb = make_shared<BuildFerrir>();

        spd->construct(bb);
        spd->construct(fb);

        auto bp = bb->getProduct();
        auto fp = fb->getProduct();

        bp->showCar();
        fp->showCar();
    }

    // 代理模式
    if (1) {
        cout << "代理模式" << endl;
        auto pProxy = make_shared<Proxy>();
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
        B->operation();
    }

    // 外观模式
    if (1)
    {
        cout << "外观模式" << endl;
        auto spFacade = make_shared<Facade>();
        spFacade->method();
    }


    // 模板方法模式
    if(0)
    {
        cout << "模板方法模式" << endl;
        auto A = make_shared<MethodA>();
        auto B = make_shared<MethodB>();
        A->templateMethod();
        B->templateMethod();
    }

    // 策略模式
    if (1) {
        cout << "策略模式" << endl;
        auto spContextA = make_shared<Context>(0);
        spContextA->doSomething(100);

        auto spContextB = make_shared<Context>(1);
        spContextB->doSomething(100);
    }

    // 状态模式
    if (1)
    {
        cout << "状态模式" << endl;
        auto spContext = make_shared<State::Context>();
        spContext->request();
        spContext->request();
        spContext->request();
        spContext->request();
        spContext->request();
    }
    
}

