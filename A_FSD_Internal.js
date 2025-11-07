const { MongoClient } = require("mongodb");

const uri = "mongodb+srv://divyasrimeghanameka:<password>@cluster0.b73uwpk.mongodb.net/?appName=Cluster0";
const client = new MongoClient(uri);//Divvyasrimeghanameka

async function run() {
  try {
    await client.connect();
    console.log("Connected to MongoDB Atlas");

    const db = client.db("schoolDB");
    const students = db.collection("students");

    await db.createCollection("teachers");
    console.log("'teachers' collection created in 'schoolDB'");

    await students.insertOne({ name: "Alice", grade: "A" });
    console.log("Inserted a document into 'students' collection");

    await db.collection("teachers").drop();
    console.log("'teachers' collection dropped");

    await db.dropDatabase();
    console.log("'schoolDB' database dropped");
  } catch (error) {
    console.error("Error:", error);
  } finally {
    await client.close();
    console.log("Connection closed");
  }
}

run();
