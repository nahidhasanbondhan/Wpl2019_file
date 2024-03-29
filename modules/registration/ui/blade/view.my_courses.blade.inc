<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_teacherbao.inc';


$_CourseTeacherBAO = new CourseTeacherBAO();
$_DB = DBUtil::getInstance();
$_RegistrationSessionBAO = new RegistrationSessionBAO();
$_YearBAO = new YearBAO();
$_TermBAO = new TermBAO();
$CourseTeacher = new CourseTeacher();

$globalUser = $_SESSION["globalUser"];

if(isset($_GET['find_courses']))
{

    $CourseTeacher->setTeacher($globalUser->getID());
    $CourseTeacher->setSession($_GET['session']);

    $Result_My_Courses = $_CourseTeacherBAO->getAllMyCourses($CourseTeacher);

}

if(isset($_GET['edit'])){

    $CourseTeacher->setID($_GET['edit']);
    $getROW = $_CourseTeacherBAO->readCourseTeacher($CourseTeacher)->getResultObject();

    $CourseTeacher->setTeacher($getROW->getTeacher()->getID());
    $CourseTeacher->setSession($getROW->getSession()->getID());
    $CourseTeacher->setYear($getROW->getYear()->getID());
    $CourseTeacher->setTerm($getROW->getTerm()->getID());

    $Result_My_Courses = $_CourseTeacherBAO->getAllMyCourses($CourseTeacher);
}

if(isset($_GET['update'])){

    $NoOfTests=$_GET['txtTestCount'];
    $IdRT=$_GET['txtRowID'];
    echo $NoOfTests;

    $Result = $_CourseTeacherBAO->updateCourseNoOfTests($IdRT,$NoOfTests);

    $Result_My_Courses = $_CourseTeacherBAO->getAllMyCourses($CourseTeacher);
    $getROW = $_CourseTeacherBAO->readCourseTeacher($CourseTeacher)->getResultObject();


}


//$_Log->log(LogUtil::$DEBUG," exit view.my_courses.blade.inc");

?>
