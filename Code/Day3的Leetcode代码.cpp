class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 如果是空或者下一个为空
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 定义next指针
        ListNode* next = head->next;
        // 如果next的值与head的值相同，更新next的位置
        if (head->val == next->val) {
            while (next != nullptr && head->val == next->val) {
                next = next->next;
            }
            // 这里是和删除排序链表中的重复元素II 唯一不同的地方，就是不是更新head的位置，而是更新其next的位置
            head->next = deleteDuplicates(next);
        }
        else {
            head->next = deleteDuplicates(next);
        }
        return head;
    }
};

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int days = 0;
        int times = 1;

        int month_day_leap[11] =
        { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
        int month_day_nleap[11] =
        { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
        string whatday[7] = { "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" };

        if (year % 100 == 0)
        {
            if (year == 2000)// 闰年 
            {

                while (times < month)
                {
                    days += month_day_leap[times - 1]; times++;
                }
                days += day;

            }
            else//非闰年
            {
                while (times < month)
                {
                    days += month_day_nleap[times - 1]; times++;
                }
                days += day;
            }
        }
        else
        {
            if (year % 4 == 0)//LEAP YEAR
            {
                while (times < month)
                {
                    days += month_day_leap[times - 1]; times++;
                }
                days += day;
            }
            else
            {
                while (times < month)
                {
                    days += month_day_nleap[times - 1]; times++;
                }
                days += day;
            }
        }
        while (year > 1971)
        {
            year--;
            if (year == 2000)
                days += 366;
            else if (year % 100 == 0 || year % 4 != 0)
                days += 365;
            else if (year % 4 == 0)
                days += 366;
        }
        int nums = days % 7 - 1;
        if (nums == -1) nums = 6;
        return whatday[nums];
    };
};