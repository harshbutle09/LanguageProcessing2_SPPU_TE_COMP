import streamlit as st
from nltk.chat.util import Chat, reflections

movies = {
    "Batman": ["Morning 9:00 AM", "AfterNoon 12:00 PM", "Evening 7:00 PM"],
    "SuperMan": ["Morning 10:00 AM", "AfterNoon 1:00 PM", "Evening 8:00 PM"],
    "SpiderMan": ["Morning 11:00 AM", "AfterNoon 2:00 PM", "Evening 9:00 PM"],
    "AntMan": ["Morning 8:00 AM", "AfterNoon 3:00 PM", "Evening 11:00 PM"],
    "IronMan": ["Morning 7:00 AM", "AfterNoon 4:00 PM", "Evening 10:00 PM"]
}

# Updated Patterns
patterns = [
    (r'(?i).*\b(hey|hello|hi)\b', ["Hey there! How can I help You?"]),
    (r'(?i).*\bhow are you\b', ["I'm just a bot, but I'm here to help you book movie tickets!"]),
    (r'(?i).*\bongoing shows\b', ["Here is the list of all the ongoing shows:\n" + "\n".join(movies.keys())]),
    (r'(?i).*\btimings\b', ["Here are the show timings:\n" + "\n".join([f"{m}: {', '.join(t)}" for m, t in movies.items()])]),
    (r'(?i).*\bbook tickets\b', ["Let's proceed with booking tickets!"]),
    (r'(?i).*\b(bye|goodbye|bye-bye)\b', ["See ya! Enjoy your movie!"])
]

def book_ticket(movie, tickets, timing):
    ticket_price = 100
    total_price = tickets * ticket_price
    return f"{tickets} tickets booked for {movie} at {timing}.\nTotal Cost: ₹{total_price}"

my_bot = Chat(patterns, reflections)

# Streamlit App
st.title("Ticket Booking Chatbot")

# Initialize session state
if "chat" not in st.session_state:
    st.session_state.chat = []

if "booking_flow" not in st.session_state:
    st.session_state.booking_flow = False

user_input = st.text_input("You:", key="user_input")

if user_input:
    st.session_state.chat.append(("You", user_input))
    bot_response = my_bot.respond(user_input)

    if bot_response:
        st.session_state.chat.append(("Bot", bot_response))
    else:
        st.session_state.chat.append(("Bot", "Sorry, I didn't get that. Could you please rephrase?"))

    # Enable booking flow if user says "book tickets"
    if "book tickets" in user_input.lower():
        st.session_state.booking_flow = True

# Booking UI
if st.session_state.booking_flow:
    st.markdown("### Booking Section")
    movie = st.selectbox("Choose a Movie", list(movies.keys()))
    timing = st.selectbox("Choose Movie Timing", movies[movie])
    tickets = st.number_input("Enter Number of tickets", min_value=1, max_value=10, step=1)

    if st.button("Confirm Booking"):
        booking_message = book_ticket(movie, tickets, timing)
        st.session_state.chat.append(("Bot", booking_message))
        st.session_state.booking_flow = False  # reset flow after booking

# Show chat
st.write("### Conversations")
for speaker, message in st.session_state.chat:
    st.markdown(f"**{speaker}:** {message}")
