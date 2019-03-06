package com.lll.commonjni;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.lll.commonjni.utils.JNIUtils;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnClick;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    @BindView(R.id.sample_text)
    TextView sampleText;
    @BindView(R.id.btn_execute)
    Button btnExecute;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);
        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);

        tv.setText(new JNIUtils().stringFromJNI());
    }


    @OnClick({R.id.btn_execute, R.id.btn_executeCppFunc, R.id.btn_executeCppClass,
            R.id.btn_executeCppCopy, R.id.btn_executeInitAttribute, R.id.btn_executeStaticKey,
            R.id.btn_executePointerRefdiff, R.id.btn_callCppOperator, R.id.btn_callCppBackets,
            R.id.btn_callCppextends, R.id.btn_callAbstractClass,R.id.btn_callFuncPointer})
    public void onViewClicked(View view) {
        switch (view.getId()) {
            case R.id.btn_execute: {
                Log.e(TAG, "NDK点击执行..");
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.executeCppConst();
                break;
            }
            case R.id.btn_executeCppFunc: {
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.executeCppFuncPointer();// 方法指针
            }
            case R.id.btn_executeCppClass: {// class 定义
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.executeCppClass();
                break;
            }
            case R.id.btn_executeCppCopy: {// 浅拷贝和深拷贝
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.executeCppCopy();
                break;
            }
            case R.id.btn_executeInitAttribute: {
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.initObjectAttribute();
                break;
            }
            case R.id.btn_executeStaticKey: {
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.executeStaticKey();
                break;
            }
            case R.id.btn_executePointerRefdiff: {
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.callCppPointerAndRefDiff();
                break;
            }
            case R.id.btn_callCppOperator: {
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.callCppOperator();
                Log.e(TAG, "callCppOperator-操作运算符");
                break;
            }
            case R.id.btn_callCppBackets: {
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.callCppBackets();
                Log.e(TAG, "callCppBackets- ()操作运算符");
                break;
            }
            case R.id.btn_callCppextends: {
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.callCppextends(); // 执行报错！！！
                Log.e(TAG, "callCppextends- 继承和初始化父类属性");
                break;
            }
            //
            case R.id.btn_callAbstractClass: {
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.callCppAbstractClass(); // 执行报错！！！
                Log.e(TAG, "callCppextends- 抽象类（纯虚构函数）");
                break;
            }//
            case R.id.btn_callFuncPointer: {
                NDKCppInteface ndkCppInteface = new NDKCppInteface();
                ndkCppInteface.callFuncPointer(); // 执行报错！！！
                Log.e(TAG, "callCppextends- 函数指针作为函数参数");
                break;
            }
        }
    }
}
