//hiding all unecessary information and showing oonly the important ones
//easiest way to implement these are access modifiers
///In programming, it means you don’t need to know how something works internally, you just need to know what it does.
// Simplicity → Makes complex systems easier to use.
// (You don’t need to learn the engine mechanics to drive a car.)

// Security → Hides implementation details that shouldn’t be exposed.

// Flexibility → You can change the internal code later without affecting users.
// (For example, you can upgrade the car engine, but the driver still uses accelerator/brake the same way.)

// Maintainability → Makes big projects easier to manage, since different parts are separated.

#include <iostream>
#include <string>
using namespace std;

class shape{
    virtual void draw() =  0;  // pure virtual functions
};

class Circle : public shape {
    public:
        void draw() {
            cout << "drawing a circlee" ;
        }
};

int main() {
    Circle c1;
    c1.draw();
    return 0;
}


#include <iostream>
using namespace std;

// Abstract class (cannot be instantiated directly)
class Shape {
public:
    // Pure virtual function (no implementation here)
    virtual void draw() = 0;
};

// Derived class 1
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle ⚪" << endl;
    }
};

// Derived class 2
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle ▭" << endl;
    }
};

int main() {
    // We can use Shape* to point to different shapes
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw(); // Output: Drawing a Circle ⚪
    shape2->draw(); // Output: Drawing a Rectangle ▭

    delete shape1;
    delete shape2;
    return 0;
}





//------------------------------------------------------------
#include <iostream>              // Gives us std::cout for printing to the console
using namespace std;             // So we can write cout instead of std::cout

// Abstract base class: it defines WHAT a Shape can do, not HOW it does it.
class Shape {
public:
    // Pure virtual function: "= 0" means NO implementation here.
    // Any class that inherits Shape MUST provide its own draw().
    virtual void draw() = 0;
};

// Concrete class Circle: provides HOW a circle draws itself.
class Circle : public Shape {
public:
    void draw() override {       // 'override' ensures we're overriding a virtual function from Shape
        cout << "Drawing a Circle ⚪" << endl;
    }
};

// Concrete class Rectangle: provides HOW a rectangle draws itself.
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle ▭" << endl;
    }
};

int main() {
    // We can't create Shape directly (it's abstract), but we can use Shape* to point to real shapes.
    Shape* shape1 = new Circle();        // Treat a Circle as a generic Shape
    Shape* shape2 = new Rectangle();     // Treat a Rectangle as a generic Shape

    shape1->draw();   // Calls Circle::draw() — decided at runtime (polymorphism)
    shape2->draw();   // Calls Rectangle::draw()

    delete shape1;    // Clean up memory allocated with new
    delete shape2;    // Clean up memory allocated with new
    return 0;         // Program ends
}


// What’s the abstraction here?

// Shape exposes the idea that “every shape can draw()” (the what).

// Circle and Rectangle hide how they draw (the how).

// Code that uses shapes doesn’t need to know the internal details—just calls draw().

// (Optional real-world tip: in modern C++, prefer smart pointers like unique_ptr<Shape> to avoid manual delete.)







// Great question 👌 this line in C++ packs a LOT of concepts (inheritance, polymorphism, heap memory). Let’s **unpack it step by step**:

// ---

// ## Code in question:

// ```cpp
// Shape* shape1 = new Circle();
// ```

// ---

// ## 🔎 Step by Step What Happens

// ### 1. `new Circle()`

// * `new` means:

//   1. Allocate memory on the **heap** big enough to store a `Circle` object.
//   2. Call the **constructor** of `Circle` to initialize it.
//   3. Return the **address** of that object.

// So after this, we have a `Circle` object created in heap memory.

// ---

// ### 2. `Shape* shape1 = ...`

// * `shape1` is a **pointer to Shape**.
// * We are storing the address of the newly created `Circle` object in it.

// So:

// * Object created → type = `Circle`
// * Pointer holding it → type = `Shape*`

// This is called **upcasting** (assigning derived-class object to a base-class pointer).

// ---

// ### 3. Why is this allowed?

// Because `Circle` **inherits from** `Shape`.
// So a `Circle` **is-a** `Shape`.
// Thus, the compiler allows a `Shape*` to point to a `Circle` object.

// ---

// ### 4. What happens when we call `shape1->draw();`

// If `draw()` is declared `virtual` in `Shape`:

// * C++ uses **dynamic dispatch** (runtime polymorphism).
// * Even though `shape1` is a `Shape*`, the actual object is a `Circle`.
// * So it will call `Circle::draw()` instead of `Shape::draw()`.

// If `draw()` is **not virtual**:

// * The compiler will use the pointer type (`Shape*`).
// * So it calls `Shape::draw()` (static binding).

// ---

// ## 📌 Visualization in Memory

// Imagine you run:

// ```cpp
// Shape* shape1 = new Circle();
// ```

// Memory looks like:

// ```
// Heap:         [ Circle object ]
//                 ↑
// Stack:   shape1 (pointer to Shape)
// ```

// Even though the **object** is `Circle`, you’re only holding a `Shape*` pointer to it.

// ---

// ## ✅ Why do we write it this way?

// 1. **Polymorphism** → we can store different derived objects in one base pointer.

//    ```cpp
//    Shape* s1 = new Circle();
//    Shape* s2 = new Rectangle();
//    Shape* s3 = new Triangle();
//    ```

//    Then loop:

//    ```cpp
//    Shape* arr[] = {s1, s2, s3};
//    for (auto s : arr) {
//        s->draw();  // Circle/Rectangle/Triangle, decided at runtime
//    }
//    ```

// 2. **Flexibility** → You don’t need to know *which* shape at compile time.

// ---

// ⚡ Small but important: since you used `new`, you must later use `delete shape1;` to free the memory. Otherwise, you’ll cause a memory leak.

// ---

// 👉 Do you want me to also explain **how vtable (virtual table) works internally** here, when you call `shape1->draw();`?
