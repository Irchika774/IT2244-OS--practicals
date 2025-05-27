@echo off
REM Create directories on Desktop
cd %USERPROFILE%\Desktop
mkdir CSC2244 Marks Exam

REM Create subdirectories inside CSC2244
cd CSC2244
mkdir practical theory "exam papers"

REM Create files inside each subdirectory
cd practical
echo. > practical.txt
echo. > practical.docx
echo. > practical.pptx
cd ..

cd theory
echo. > theory.txt
echo. > theory.docx
echo. > theory.pptx
cd ..

cd "exam papers"
echo. > exam_papers.txt
echo. > exam_papers.docx
echo. > exam_papers.pptx
cd ..\..

REM Create Excel files and move to Marks
cd %USERPROFILE%\Desktop
echo. > Icae Marks.xlsx
echo. > Final Exam Marks.xlsx
move "Icae Marks.xlsx" Marks\
move "Final Exam Marks.xlsx" Marks\

REM Copy Marks into Exam and hide Exam directory
xcopy /E /I Marks Exam\Marks
attrib +h Exam
