import java.util.*;

class Solution {
    public String solution(String m, String[] musicinfos) {
        String answer = "";
        int maxPlayTime = -1;
        m = changeMelody(m);
        for(String musicinfo : musicinfos){
            String[] info = musicinfo.split(",");
            String title = info[2]; // 노래 제목
            String melodyInfo = changeMelody(info[3]); // 치환한 멜로디 정보
            String[] timeInfo = info[0].split(":");
            int start = Integer.parseInt(timeInfo[0]) * 60 + Integer.parseInt(timeInfo[1]);
            timeInfo = info[1].split(":");
            int end = Integer.parseInt(timeInfo[0]) * 60 + Integer.parseInt(timeInfo[1]);
            int play = end - start;
            if(play > melodyInfo.length()){ // 음악 길이보다 재생된 시간이 더 길때
                StringBuilder newMelody = new StringBuilder();
                for(int i=0; i<play / melodyInfo.length(); i++)
                    newMelody.append(melodyInfo);
                
                newMelody.append(melodyInfo.substring(0,play%melodyInfo.length()));
                melodyInfo = newMelody.toString();
            }
            
            else { // 음악 길이보다 재생된 시간이 짧을 때
                melodyInfo = melodyInfo.substring(0,play);
            }
            
            if(melodyInfo.contains(m) && play > maxPlayTime){
                answer = title;
                maxPlayTime = play;
            }
        }
        
        if(maxPlayTime == -1) return "(None)";
        return answer;
    }
    public String changeMelody(String oldMelody){
        oldMelody = oldMelody.replaceAll("C#","L");
        oldMelody = oldMelody.replaceAll("D#","M");
        oldMelody = oldMelody.replaceAll("F#","N");
        oldMelody = oldMelody.replaceAll("G#","O");
        String newMelody = oldMelody.replaceAll("A#","P");
        
        return newMelody;
    }
}