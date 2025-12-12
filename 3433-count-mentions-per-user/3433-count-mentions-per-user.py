class Solution:
    def countMentions(self, numberOfUsers, events):
        # Sort events by timestamp, and for same timestamp, OFFLINE before MESSAGE
        events.sort(key=lambda x: (int(x[1]), 0 if x[0] == "OFFLINE" else 1))
        
        mentions = [0] * numberOfUsers
        offline_until = [0] * numberOfUsers  # 0 means online
        
        for event in events:
            event_type, timestamp_str, data = event
            timestamp = int(timestamp_str)
            
            # First, process any users coming back online at this timestamp
            for i in range(numberOfUsers):
                if offline_until[i] > 0 and offline_until[i] <= timestamp:
                    offline_until[i] = 0  # User comes back online
            
            if event_type == "OFFLINE":
                user = int(data)
                offline_until[user] = timestamp + 60
            elif event_type == "MESSAGE":
                if data == "ALL":
                    # Mention all users
                    for i in range(numberOfUsers):
                        mentions[i] += 1
                elif data == "HERE":
                    # Mention only online users
                    for i in range(numberOfUsers):
                        if offline_until[i] == 0:  # Online
                            mentions[i] += 1
                else:
                    # Parse "idX idY ..." string
                    # Split by space and extract user IDs
                    tokens = data.split()
                    for token in tokens:
                        # token is like "id0", "id1", etc.
                        user = int(token[2:])  # Skip "id"
                        mentions[user] += 1
        
        return mentions