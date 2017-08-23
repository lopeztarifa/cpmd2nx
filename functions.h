#!/bin/bash
# Lowpez is helping cpmd2nx.sh 
# PS tons of pain handeling the flotating real numbers of the masess ...
# next time I will use PERL
# PLT@EPFL(2014)
#
   source include.h &>/dev/null
       if [ $? != 0 ]; then echo 'include.h is missed!'; exit; fi
   . include.h
#
#
  check_file () {
       ls $1  &>/dev/null
      if [ $? == 0 ] ; then let $2=1;
      else echo ""; echo "#########"; echo "WARNNING!"; echo "#########";
           echo "The $1 file is missed!"
           echo "you should copy it afterwards for each of the TRAJ# folders generated!"
           let $2=0
           echo ""
      fi
           }
# 
   mass_zatom ()  {
 if [ ${s[$1]} = H  ]; then Zatom[$1]=$zH  ; mass[$1]=$mH  ; fi  
 if [ ${s[$1]} = D  ]; then Zatom[$1]=$zD  ; mass[$1]=$mD  ; fi 
 if [ ${s[$1]} = T  ]; then Zatom[$1]=$zT  ; mass[$1]=$mT  ; fi 
 if [ ${s[$1]} = He ]; then Zatom[$1]=$zHe ; mass[$1]=$mHe ; fi 
 if [ ${s[$1]} = Li ]; then Zatom[$1]=$zLi ; mass[$1]=$mLi ; fi 
 if [ ${s[$1]} = Be ]; then Zatom[$1]=$zBe ; mass[$1]=$mBe ; fi 
 if [ ${s[$1]} = B  ]; then Zatom[$1]=$zB  ; mass[$1]=$mB  ; fi 
 if [ ${s[$1]} = C  ]; then Zatom[$1]=$zC  ; mass[$1]=$mC  ; fi 
 if [ ${s[$1]} = N  ]; then Zatom[$1]=$zN  ; mass[$1]=$mN  ; fi 
 if [ ${s[$1]} = O  ]; then Zatom[$1]=$zO  ; mass[$1]=$mO  ; fi 
 if [ ${s[$1]} = F  ]; then Zatom[$1]=$zF  ; mass[$1]=$mF  ; fi 
 if [ ${s[$1]} = Ne ]; then Zatom[$1]=$zNe ; mass[$1]=$mNe ; fi 
 if [ ${s[$1]} = Na ]; then Zatom[$1]=$zNa ; mass[$1]=$mNa ; fi 
 if [ ${s[$1]} = Mg ]; then Zatom[$1]=$zMg ; mass[$1]=$mMg ; fi 
 if [ ${s[$1]} = Al ]; then Zatom[$1]=$zAl ; mass[$1]=$mAl ; fi 
 if [ ${s[$1]} = Si ]; then Zatom[$1]=$zSi ; mass[$1]=$mSi ; fi 
 if [ ${s[$1]} = P  ]; then Zatom[$1]=$zP  ; mass[$1]=$mP  ; fi 
 if [ ${s[$1]} = S  ]; then Zatom[$1]=$zS  ; mass[$1]=$mS  ; fi 
 if [ ${s[$1]} = Cl ]; then Zatom[$1]=$zCl ; mass[$1]=$mCl ; fi 
 if [ ${s[$1]} = Ar ]; then Zatom[$1]=$zAr ; mass[$1]=$mAr ; fi 
 if [ ${s[$1]} = K  ]; then Zatom[$1]=$zK  ; mass[$1]=$mK  ; fi 
 if [ ${s[$1]} = Ca ]; then Zatom[$1]=$zCa ; mass[$1]=$mCa ; fi 
 if [ ${s[$1]} = Sc ]; then Zatom[$1]=$zSc ; mass[$1]=$mSc ; fi 
 if [ ${s[$1]} = Ti ]; then Zatom[$1]=$zTi ; mass[$1]=$mTi ; fi 
 if [ ${s[$1]} = V  ]; then Zatom[$1]=$zV  ; mass[$1]=$mV  ; fi 
 if [ ${s[$1]} = Cr ]; then Zatom[$1]=$zCr ; mass[$1]=$mCr ; fi 
 if [ ${s[$1]} = Mn ]; then Zatom[$1]=$zMn ; mass[$1]=$mMn ; fi 
 if [ ${s[$1]} = Fe ]; then Zatom[$1]=$zFe ; mass[$1]=$mFe ; fi 
 if [ ${s[$1]} = Co ]; then Zatom[$1]=$zCo ; mass[$1]=$mCo ; fi 
 if [ ${s[$1]} = Ni ]; then Zatom[$1]=$zNi ; mass[$1]=$mNi ; fi 
 if [ ${s[$1]} = Cu ]; then Zatom[$1]=$zCu ; mass[$1]=$mCu ; fi 
 if [ ${s[$1]} = Zn ]; then Zatom[$1]=$zZn ; mass[$1]=$mZn ; fi 
 if [ ${s[$1]} = Ga ]; then Zatom[$1]=$zGa ; mass[$1]=$mGa ; fi 
 if [ ${s[$1]} = Ge ]; then Zatom[$1]=$zGe ; mass[$1]=$mGe ; fi 
 if [ ${s[$1]} = As ]; then Zatom[$1]=$zAs ; mass[$1]=$mAs ; fi 
 if [ ${s[$1]} = Se ]; then Zatom[$1]=$zSe ; mass[$1]=$mSe ; fi 
 if [ ${s[$1]} = Br ]; then Zatom[$1]=$zBr ; mass[$1]=$mBr ; fi 
 if [ ${s[$1]} = Kr ]; then Zatom[$1]=$zKr ; mass[$1]=$mKr ; fi 
 if [ ${s[$1]} = Rb ]; then Zatom[$1]=$zRb ; mass[$1]=$mRb ; fi 
 if [ ${s[$1]} = Sr ]; then Zatom[$1]=$zSr ; mass[$1]=$mSr ; fi 
 if [ ${s[$1]} = Y  ]; then Zatom[$1]=$zY  ; mass[$1]=$mY  ; fi 
 if [ ${s[$1]} = Zr ]; then Zatom[$1]=$zZr ; mass[$1]=$mZr ; fi 
 if [ ${s[$1]} = Nb ]; then Zatom[$1]=$zNb ; mass[$1]=$mNb ; fi 
 if [ ${s[$1]} = Mo ]; then Zatom[$1]=$zMo ; mass[$1]=$mMo ; fi 
 if [ ${s[$1]} = Tc ]; then Zatom[$1]=$zTc ; mass[$1]=$mTc ; fi 
 if [ ${s[$1]} = Ru ]; then Zatom[$1]=$zRu ; mass[$1]=$mRu ; fi 
 if [ ${s[$1]} = Rh ]; then Zatom[$1]=$zRh ; mass[$1]=$mRh ; fi 
 if [ ${s[$1]} = Pd ]; then Zatom[$1]=$zPd ; mass[$1]=$mPd ; fi 
 if [ ${s[$1]} = Ag ]; then Zatom[$1]=$zAg ; mass[$1]=$mAg ; fi 
 if [ ${s[$1]} = Cd ]; then Zatom[$1]=$zCd ; mass[$1]=$mCd ; fi 
 if [ ${s[$1]} = In ]; then Zatom[$1]=$zIn ; mass[$1]=$mIn ; fi 
 if [ ${s[$1]} = Sn ]; then Zatom[$1]=$zSn ; mass[$1]=$mSn ; fi 
 if [ ${s[$1]} = Sb ]; then Zatom[$1]=$zSb ; mass[$1]=$mSb ; fi 
 if [ ${s[$1]} = Te ]; then Zatom[$1]=$zTe ; mass[$1]=$mTe ; fi 
 if [ ${s[$1]} = I  ]; then Zatom[$1]=$zI  ; mass[$1]=$mI  ; fi 
 if [ ${s[$1]} = Xe ]; then Zatom[$1]=$zXe ; mass[$1]=$mXe ; fi 
 if [ ${s[$1]} = Cs ]; then Zatom[$1]=$zCs ; mass[$1]=$mCs ; fi 
 if [ ${s[$1]} = Ba ]; then Zatom[$1]=$zBa ; mass[$1]=$mBa ; fi 
 if [ ${s[$1]} = La ]; then Zatom[$1]=$zLa ; mass[$1]=$mLa ; fi 
 if [ ${s[$1]} = Ce ]; then Zatom[$1]=$zCe ; mass[$1]=$mCe ; fi 
 if [ ${s[$1]} = Pr ]; then Zatom[$1]=$zPr ; mass[$1]=$mPr ; fi 
 if [ ${s[$1]} = Nd ]; then Zatom[$1]=$zNd ; mass[$1]=$mNd ; fi 
 if [ ${s[$1]} = Pm ]; then Zatom[$1]=$zPm ; mass[$1]=$mPm ; fi 
 if [ ${s[$1]} = Sm ]; then Zatom[$1]=$zSm ; mass[$1]=$mSm ; fi 
 if [ ${s[$1]} = Eu ]; then Zatom[$1]=$zEu ; mass[$1]=$mEu ; fi 
 if [ ${s[$1]} = Gd ]; then Zatom[$1]=$zGd ; mass[$1]=$mGd ; fi 
 if [ ${s[$1]} = Tb ]; then Zatom[$1]=$zTb ; mass[$1]=$mTb ; fi 
 if [ ${s[$1]} = Dy ]; then Zatom[$1]=$zDy ; mass[$1]=$mDy ; fi 
 if [ ${s[$1]} = Ho ]; then Zatom[$1]=$zHo ; mass[$1]=$mHo ; fi 
 if [ ${s[$1]} = Er ]; then Zatom[$1]=$zEr ; mass[$1]=$mEr ; fi 
 if [ ${s[$1]} = Tm ]; then Zatom[$1]=$zTm ; mass[$1]=$mTm ; fi 
 if [ ${s[$1]} = Yb ]; then Zatom[$1]=$zYb ; mass[$1]=$mYb ; fi 
 if [ ${s[$1]} = Lu ]; then Zatom[$1]=$zLu ; mass[$1]=$mLu ; fi 
 if [ ${s[$1]} = Hf ]; then Zatom[$1]=$zHf ; mass[$1]=$mHf ; fi 
 if [ ${s[$1]} = Ta ]; then Zatom[$1]=$zTa ; mass[$1]=$mTa ; fi 
 if [ ${s[$1]} = W  ]; then Zatom[$1]=$zW  ; mass[$1]=$mW  ; fi 
 if [ ${s[$1]} = Re ]; then Zatom[$1]=$zRe ; mass[$1]=$mRe ; fi 
 if [ ${s[$1]} = Os ]; then Zatom[$1]=$zOs ; mass[$1]=$mOs ; fi 
 if [ ${s[$1]} = Ir ]; then Zatom[$1]=$zIr ; mass[$1]=$mIr ; fi 
 if [ ${s[$1]} = Pt ]; then Zatom[$1]=$zPt ; mass[$1]=$mPt ; fi 
 if [ ${s[$1]} = Au ]; then Zatom[$1]=$zAu ; mass[$1]=$mAu ; fi 
 if [ ${s[$1]} = Hg ]; then Zatom[$1]=$zHg ; mass[$1]=$mHg ; fi 
 if [ ${s[$1]} = Tl ]; then Zatom[$1]=$zTl ; mass[$1]=$mTl ; fi 
 if [ ${s[$1]} = Pb ]; then Zatom[$1]=$zPb ; mass[$1]=$mPb ; fi 
 if [ ${s[$1]} = Bi ]; then Zatom[$1]=$zBi ; mass[$1]=$mBi ; fi 
 if [ ${s[$1]} = Po ]; then Zatom[$1]=$zPo ; mass[$1]=$mPo ; fi 
 if [ ${s[$1]} = At ]; then Zatom[$1]=$zAt ; mass[$1]=$mAt ; fi 
 if [ ${s[$1]} = Rn ]; then Zatom[$1]=$zRn ; mass[$1]=$mRn ; fi 
 if [ ${s[$1]} = Fr ]; then Zatom[$1]=$zFr ; mass[$1]=$mFr ; fi 
 if [ ${s[$1]} = Ra ]; then Zatom[$1]=$zRa ; mass[$1]=$mRa ; fi 
 if [ ${s[$1]} = Ac ]; then Zatom[$1]=$zAc ; mass[$1]=$mAc ; fi 
 if [ ${s[$1]} = Th ]; then Zatom[$1]=$zTh ; mass[$1]=$mTh ; fi 
 if [ ${s[$1]} = Pa ]; then Zatom[$1]=$zPa ; mass[$1]=$mPa ; fi 
 if [ ${s[$1]} = U  ]; then Zatom[$1]=$zU  ; mass[$1]=$mU  ; fi 
 if [ ${s[$1]} = Np ]; then Zatom[$1]=$zNp ; mass[$1]=$mNp ; fi 
 if [ ${s[$1]} = Pu ]; then Zatom[$1]=$zPu ; mass[$1]=$mPu ; fi 
 if [ ${s[$1]} = Am ]; then Zatom[$1]=$zAm ; mass[$1]=$mAm ; fi 
 if [ ${s[$1]} = Cm ]; then Zatom[$1]=$zCm ; mass[$1]=$mCm ; fi 
 if [ ${s[$1]} = Bk ]; then Zatom[$1]=$zBk ; mass[$1]=$mBk ; fi 
 if [ ${s[$1]} = Cf ]; then Zatom[$1]=$zCf ; mass[$1]=$mCf ; fi 
 if [ ${s[$1]} = Es ]; then Zatom[$1]=$zEs ; mass[$1]=$mEs ; fi 
 if [ ${s[$1]} = Fm ]; then Zatom[$1]=$zFm ; mass[$1]=$mFm ; fi 
 if [ ${s[$1]} = Md ]; then Zatom[$1]=$zMd ; mass[$1]=$mMd ; fi 
 if [ ${s[$1]} = No ]; then Zatom[$1]=$zNo ; mass[$1]=$mNo ; fi 
 if [ ${s[$1]} = Lr ]; then Zatom[$1]=$zLr ; mass[$1]=$mLr ; fi 
 if [ ${s[$1]} = Rf ]; then Zatom[$1]=$zRf ; mass[$1]=$mRf ; fi 
 if [ ${s[$1]} = Db ]; then Zatom[$1]=$zDb ; mass[$1]=$mDb ; fi 
 if [ ${s[$1]} = Sg ]; then Zatom[$1]=$zSg ; mass[$1]=$mSg ; fi 
 if [ ${s[$1]} = Bh ]; then Zatom[$1]=$zBh ; mass[$1]=$mBh ; fi 
 if [ ${s[$1]} = Hs ]; then Zatom[$1]=$zHs ; mass[$1]=$mHs ; fi 
 if [ ${s[$1]} = Mt ]; then Zatom[$1]=$zMt ; mass[$1]=$mMt ; fi 
 if [ ${s[$1]} = Ds ]; then Zatom[$1]=$zDs ; mass[$1]=$mDs ; fi 
                   }
#
   good_end ()  {
                 echo ""
                 echo "       JOB DONE!"
                 echo ""
                 echo "               EMBRACE THE RANDOMNESS OF LIFE!"
                 echo ""
                }
