# fastddsdemo-new


## HelloWorld.cxx line 108
move "current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;"

to "current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 1024*20 + 1;"

