class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // ����ǿջ�����һ��Ϊ��
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // ����nextָ��
        ListNode* next = head->next;
        // ���next��ֵ��head��ֵ��ͬ������next��λ��
        if (head->val == next->val) {
            while (next != nullptr && head->val == next->val) {
                next = next->next;
            }
            // �����Ǻ�ɾ�����������е��ظ�Ԫ��II Ψһ��ͬ�ĵط������ǲ��Ǹ���head��λ�ã����Ǹ�����next��λ��
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
            if (year == 2000)// ���� 
            {

                while (times < month)
                {
                    days += month_day_leap[times - 1]; times++;
                }
                days += day;

            }
            else//������
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