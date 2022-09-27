#ifndef __TEST_QUEUE_H__
#define __TEST_QUEUE_H__

#include <gtest/gtest.h>

#include <queue>

using namespace std;

template <typename T>
class Queue {
   private:
    /* data */
    queue<T> que;

   public:
    Queue(/* args */) {}
    void Enqueue(const T& element) {
        que.push(element);
    }
    T Dequeue() {
        T data = que.front();
        que.pop();
        return data;
    }

    size_t size() const {
        return que.size();
    }
    ~Queue() {}
};


// Fixture class
class QueueTest : public ::testing::Test {
   protected:
    void SetUp() override {
        q1_.Enqueue(1);
        q2_.Enqueue(2);
        q2_.Enqueue(3);
    }

    void TearDown() override {}

    Queue<int> q0_;
    Queue<int> q1_;
    Queue<int> q2_;
};

TEST_F(QueueTest, IsEmptyInitially) {
    EXPECT_EQ(q0_.size(), 0);
}

TEST_F(QueueTest, DequeueWorks) {
    int n = q0_.size();
    EXPECT_EQ(n, 0);

    n = q1_.Dequeue();
    EXPECT_EQ(n, 1);
    EXPECT_EQ(q1_.size(), 0);

    n = q2_.Dequeue();
    EXPECT_EQ(n, 2);
    EXPECT_EQ(q2_.size(), 1);
}

#endif