declare
    empname emp.ename%rowtype := 'Blake';
    empjob emp.job%rowtype;

begin 
    select e.job
    from emp e
    into empjob
    where e.ename = empname;

    if empjob = 'manager' or empjob = 'analyst'
        then update emp
             set sal := 1.15*sal
             where ename = empname;

        else update emp
             set sal := 0.88*sal
             where ename = empname;
    end if;
    dbms_output.put_line('Values are successfully updated');
    select * from emp;

    exception
        when no_data_found
            then dbms_output.put_line('Employee '||empname||' not found');
        when others
            then dbms_output.put_line('Error : '|| sqlerrm);
    end;
end;