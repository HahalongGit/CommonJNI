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
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(new JNIUtils().stringFromJNI());
    }


    @OnClick({R.id.btn_execute, R.id.btn_executeCppFunc, R.id.btn_executeCppClass})
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
        }
    }
}
