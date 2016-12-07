package com.yaobin.audio_communication;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.ToggleButton;
import android.widget.CompoundButton.OnCheckedChangeListener;

public class Audio_communication extends Activity {
	EditText msgSendET;
	Button sendMsgBT;
	TextView RecMsgTV;
	ToggleButton recordTB;
	MessageOut msgout;
	MessageRec msgrec;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		//»´∆¡œ‘ æ
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,WindowManager.LayoutParams.FLAG_FULLSCREEN);
		
		setContentView(R.layout.activity_audio_communication);
		msgSendET=(EditText)findViewById(R.id.editText1);
		sendMsgBT=(Button) findViewById(R.id.button1);
		RecMsgTV=(TextView)findViewById(R.id.textView1);
		recordTB = (ToggleButton) findViewById(R.id.toggleButton1);
		msgout = new MessageOut();
		msgrec = new MessageRec();
		if(msgout!=null)
			msgout.StartAudio();
		sendMsgButtionProcess();
		recordButtonProcess();
	}
	private void sendMsgButtionProcess(){
		sendMsgBT.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				byte bytedata=(byte)Integer.parseInt(msgSendET.getText().toString());
				msgout.SendData(bytedata);	
			}
		});
	}
	private void recordButtonProcess(){
		recordTB.setOnCheckedChangeListener(new OnCheckedChangeListener() {
			
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
				if(isChecked){
					if(msgrec==null)msgrec = new MessageRec();
					msgrec.StartRecord();
				}
				else{
					msgrec.StopRecord();
					msgrec=null;
				}
			}
		});
	}
	@Override
	protected void onDestroy() {
		// TODO Auto-generated method stub
		super.onDestroy();
		if(msgout!=null){
			msgout.StopAudio();
			msgout=null;
		}
		if(msgrec!=null){
			msgrec.StopRecord();
			msgrec=null;
		}
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.audio_communication, menu);
		return true;
	}
}
